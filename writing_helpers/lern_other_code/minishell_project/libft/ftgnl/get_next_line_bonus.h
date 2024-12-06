/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:12:49 by dmoroz            #+#    #+#             */
/*   Updated: 2024/04/14 11:58:58 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_fd_buffer
{
	int					fd;
	char				buffer[BUFFER_SIZE];
	ssize_t				buffer_pos;
	struct s_fd_buffer	*next;
}						t_fd_buffer;

char					*get_next_line(int fd);
char					*my_strnjoin(char *line, char *buffer,
							unsigned int buff_n, unsigned int *line_size);
t_fd_buffer				*get_fd_buffer(t_fd_buffer **fd_buffers, int fd);
void					free_fd_buffer(t_fd_buffer **fd_buffers, int fd,
							t_fd_buffer *prev);

#endif
