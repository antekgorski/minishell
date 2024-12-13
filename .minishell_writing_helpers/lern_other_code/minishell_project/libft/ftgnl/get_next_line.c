/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:12:09 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/10 12:03:50 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	move_n_check(char *buffer, ssize_t *buffer_pos, char **line,
		unsigned int *line_size)
{
	unsigned int	i;
	unsigned int	ret_val;
	char			*temp;

	i = -1;
	while (++i < *buffer_pos)
		if (buffer[i] == '\n')
			break ;
	ret_val = i < *buffer_pos;
	if (i < *buffer_pos)
		i++;
	temp = my_strnjoin(*line, buffer, i, line_size);
	if (temp != *line)
	{
		free(*line);
		*line = temp;
	}
	ft_memmove(buffer, buffer + i, *buffer_pos - i);
	*buffer_pos -= i;
	return (ret_val);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	buffer_pos = 0;
	char			*res;
	unsigned int	res_size;

	res_size = 11;
	res = (char *)malloc(sizeof(char) * res_size);
	if (!res)
		return (NULL);
	res[0] = 0;
	if (buffer_pos > 0 && move_n_check(buffer, &buffer_pos, &res, &res_size))
		return (res);
	buffer_pos = read(fd, buffer, BUFFER_SIZE);
	while (buffer_pos > 0)
	{
		if (!res || move_n_check(buffer, &buffer_pos, &res, &res_size))
			return (res);
		buffer_pos = read(fd, buffer, BUFFER_SIZE);
	}
	if (res[0] && buffer_pos >= 0)
		return (res);
	free(res);
	return (NULL);
}
