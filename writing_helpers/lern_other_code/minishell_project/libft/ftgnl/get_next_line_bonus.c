/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:12:09 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/10 12:04:17 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	move_n_check(t_fd_buffer *fd_buffer, char **line, unsigned int *line_size)
{
	unsigned int	i;
	unsigned int	ret_val;
	char			*temp;

	i = -1;
	while (++i < fd_buffer->buffer_pos)
		if (fd_buffer->buffer[i] == '\n')
			break ;
	ret_val = i < fd_buffer->buffer_pos;
	if (i < fd_buffer->buffer_pos)
		i++;
	temp = my_strnjoin(*line, fd_buffer->buffer, i, line_size);
	if (temp != *line)
	{
		free(*line);
		*line = temp;
	}
	ft_memmove(fd_buffer->buffer, fd_buffer->buffer + i, fd_buffer->buffer_pos
		- i);
	fd_buffer->buffer_pos -= i;
	return (ret_val);
}

char	*get_next_line(int fd)
{
	static t_fd_buffer	*fd_buffers = NULL;
	t_fd_buffer			*cfb;
	char				*res;
	unsigned int		res_size;

	cfb = get_fd_buffer(&fd_buffers, fd);
	res_size = 11;
	res = (char *)malloc(sizeof(char) * res_size);
	if (!res)
		return (NULL);
	res[0] = 0;
	if (cfb->buffer_pos > 0 && move_n_check(cfb, &res, &res_size))
		return (res);
	cfb->buffer_pos = read(fd, cfb->buffer, BUFFER_SIZE);
	while (cfb->buffer_pos > 0)
	{
		if (!res || move_n_check(cfb, &res, &res_size))
			return (res);
		cfb->buffer_pos = read(fd, cfb->buffer, BUFFER_SIZE);
	}
	if (res[0] && cfb->buffer_pos >= 0)
		return (res);
	free_fd_buffer(&fd_buffers, fd, NULL);
	free(res);
	return (NULL);
}
