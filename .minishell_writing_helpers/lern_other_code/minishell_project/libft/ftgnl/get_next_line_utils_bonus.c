/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:18:09 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/14 11:58:49 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*my_strnjoin(char *line, char *buffer, unsigned int buff_n,
		unsigned int *line_size)
{
	char			*res;
	unsigned int	line_len;
	unsigned int	total_len;

	line_len = ft_strlen(line);
	total_len = line_len + buff_n + 1;
	if (total_len > *line_size)
	{
		*line_size *= 2;
		*line_size = *line_size * (*line_size > total_len) + total_len
			* (*line_size <= total_len);
		res = (char *)malloc(*line_size * sizeof(char));
		if (!res)
			return (NULL);
		ft_memmove(res, line, line_len);
	}
	else
		res = line;
	ft_memmove(res + line_len, buffer, buff_n);
	res[total_len - 1] = 0;
	return (res);
}

t_fd_buffer	*get_fd_buffer(t_fd_buffer **fd_buffers, int fd)
{
	t_fd_buffer	*new;

	if (*fd_buffers && (*fd_buffers)->fd == fd)
		return (*fd_buffers);
	if (*fd_buffers && (*fd_buffers)->fd != fd && (*fd_buffers)->next)
		return (get_fd_buffer(&(*fd_buffers)->next, fd));
	new = (t_fd_buffer *)malloc(sizeof(t_fd_buffer));
	new->buffer_pos = 0;
	new->fd = fd;
	new->next = NULL;
	if (*fd_buffers && (*fd_buffers)->fd != fd)
		(*fd_buffers)->next = new;
	else if (!*fd_buffers)
		*fd_buffers = new;
	return (new);
}

void	free_fd_buffer(t_fd_buffer **fd_buffers, int fd, t_fd_buffer *prev)
{
	t_fd_buffer	*tmp;

	if ((*fd_buffers)->fd != fd)
		return (free_fd_buffer(&(*fd_buffers)->next, fd, *fd_buffers));
	tmp = *fd_buffers;
	if (prev)
		prev->next = (*fd_buffers)->next;
	else
		*fd_buffers = (*fd_buffers)->next;
	free(tmp);
}
