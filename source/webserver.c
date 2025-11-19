/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:25:00 by agorski           #+#    #+#             */
/*   Updated: 2025/11/19 10:25:00 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/webserver.h"

int	init_server(t_server *server)
{
	int	opt;

	opt = 1;
	server->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server->socket_fd == -1)
	{
		perror("Socket creation failed");
		return (-1);
	}
	if (setsockopt(server->socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
	{
		perror("Setsockopt failed");
		return (-1);
	}
	server->address.sin_family = AF_INET;
	server->address.sin_addr.s_addr = INADDR_ANY;
	server->address.sin_port = htons(PORT);
	server->addrlen = sizeof(server->address);
	if (bind(server->socket_fd, (struct sockaddr *)&server->address, sizeof(server->address)) < 0)
	{
		perror("Bind failed");
		return (-1);
	}
	if (listen(server->socket_fd, MAX_CONNECTIONS) < 0)
	{
		perror("Listen failed");
		return (-1);
	}
	return (0);
}

void	send_response(int client_fd, const char *status, const char *content_type, const char *body)
{
	char	response[BUFFER_SIZE];
	int		body_len;

	body_len = strlen(body);
	snprintf(response, sizeof(response),
		"HTTP/1.1 %s\r\n"
		"Content-Type: %s\r\n"
		"Content-Length: %d\r\n"
		"Connection: close\r\n"
		"\r\n"
		"%s",
		status, content_type, body_len, body);
	write(client_fd, response, strlen(response));
}

void	serve_file(int client_fd, const char *filepath)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	char	response_header[BUFFER_SIZE];
	struct stat	file_stat;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		send_response(client_fd, "404 Not Found", "text/html",
			"<html><body><h1>404 Not Found</h1></body></html>");
		return ;
	}
	if (fstat(fd, &file_stat) < 0)
	{
		close(fd);
		send_response(client_fd, "500 Internal Server Error", "text/html",
			"<html><body><h1>500 Internal Server Error</h1></body></html>");
		return ;
	}
	snprintf(response_header, sizeof(response_header),
		"HTTP/1.1 200 OK\r\n"
		"Content-Type: text/html\r\n"
		"Content-Length: %ld\r\n"
		"Connection: close\r\n"
		"\r\n",
		file_stat.st_size);
	write(client_fd, response_header, strlen(response_header));
	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
		write(client_fd, buffer, bytes_read);
	close(fd);
}

void	handle_request(int client_fd, char *buffer)
{
	char	*method;
	char	*path;
	char	filepath[256];

	method = strtok(buffer, " ");
	path = strtok(NULL, " ");
	if (!method || !path)
	{
		send_response(client_fd, "400 Bad Request", "text/html",
			"<html><body><h1>400 Bad Request</h1></body></html>");
		return ;
	}
	if (strcmp(method, "GET") != 0)
	{
		send_response(client_fd, "405 Method Not Allowed", "text/html",
			"<html><body><h1>405 Method Not Allowed</h1></body></html>");
		return ;
	}
	if (strcmp(path, "/") == 0)
		path = "/index.html";
	snprintf(filepath, sizeof(filepath), "./www%s", path);
	serve_file(client_fd, filepath);
}

void	handle_client(int client_fd)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;

	memset(buffer, 0, sizeof(buffer));
	bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);
	if (bytes_read < 0)
	{
		perror("Read failed");
		close(client_fd);
		return ;
	}
	handle_request(client_fd, buffer);
	close(client_fd);
}

int	main(void)
{
	t_server	server;
	int			client_fd;

	printf("Initializing web server on port %d...\n", PORT);
	if (init_server(&server) < 0)
	{
		fprintf(stderr, "Failed to initialize server\n");
		return (1);
	}
	printf("Web server is running on http://localhost:%d\n", PORT);
	printf("Press Ctrl+C to stop the server\n");
	while (1)
	{
		client_fd = accept(server.socket_fd, (struct sockaddr *)&server.address,
			(socklen_t *)&server.addrlen);
		if (client_fd < 0)
		{
			perror("Accept failed");
			continue ;
		}
		printf("New connection accepted\n");
		handle_client(client_fd);
	}
	close(server.socket_fd);
	return (0);
}
