/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:18:55 by agorski           #+#    #+#             */
/*   Updated: 2024/12/22 02:55:22 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Extracts the remaining content after the first newline character
 * in a string.
 *
 * This function processes a given line to separate the content before the
 * first newline character from the content after it. It modifies the original
 * line to terminate at the newline character and returns a new string containing
 * the remaining content.
 *
 * @param line A pointer to the input string which is expected to contain
 * a newline character.
 *
 * @return A new string containing the content after the first newline character,
 * or NULL if no newline is found or if the allocated memory fails.
 *
 * @note The input string will be modified to terminate at the newline character.
 *       It is the caller's responsibility to free the memory allocated for the 
 *       returned string.
 */
static char	*read_to_buffer(char *buffer, int fd)
{
	char	*temp;
	int		bytes;

	temp = (char *)ft_calloc(sizeof(char) * (BUFFER_SIZE + 1), 1);
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
	str = (char *)ft_calloc(sizeof(char) * (i + 1), 1);
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
	str = (char *)ft_calloc(sizeof(char) * (gnl_strlen(buffer) - i + 1), 1);
	if (!str)
		return (0);
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

/**
 * @brief Reads the next line from a file descriptor.
 *
 * @param fd The file descriptor to read from.
 * 
 * @return The next line from the file descriptor, or NULL if an error occurs.
 */
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
