/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:18:55 by agorski           #+#    #+#             */
/*   Updated: 2024/11/07 13:43:46 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_to_buffer(char *buffer, int fd)
{
	char	*temp;
	int		bytes;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (0);
	bytes = 1;
	while (bytes > 0 && !gnl_strchr(buffer, '\n'))
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			if (buffer)
				free(buffer);
			free(temp);
			return (NULL);
		}
		temp[bytes] = '\0';
		buffer = gnl_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

static char	*load_to_line(char *buffer)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i] = '\0';
	while (--i + 1)
		str[i] = buffer[i];
	return (str);
}

char	*update_buffer(char *buffer)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!buffer)
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (gnl_strlen(buffer) - i + 1));
	if (!str)
		return (0);
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buffer = read_to_buffer(buffer, fd);
	if (!buffer)
		return (0);
	line = load_to_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}

// #include<stdio.h>

// int	main(void)
// {
// 	char	*line;
// 	int		fd;
// 	int		i;

// 	i = 0;
// 	fd = open("file.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("Error opening file.\n");
// 		return (1);
// 	}
// 	while((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free (line);
// 	}
// 	// while (i < 6)
// 	// {
// 	// 	line = get_next_line(fd);
// 	// 	if (line == NULL)
// 	// 		return (0);
// 	// 	printf("%s", line);
// 	// 	free(line);
// 	// 	i++;
// 	// }
// 	close(fd);
// 	return (0);
// }
