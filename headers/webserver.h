/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserver.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:25:00 by agorski           #+#    #+#             */
/*   Updated: 2025/11/19 10:25:00 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERVER_H
# define WEBSERVER_H

# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>

# define PORT 8080
# define BUFFER_SIZE 4096
# define MAX_CONNECTIONS 10

typedef struct s_server
{
	int					socket_fd;
	struct sockaddr_in	address;
	int					addrlen;
}	t_server;

int		init_server(t_server *server);
void	handle_client(int client_fd);
void	send_response(int client_fd, const char *status, const char *content_type, const char *body);
void	serve_file(int client_fd, const char *filepath);
void	handle_request(int client_fd, char *buffer);

#endif
