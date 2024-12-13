/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 05:36:53 by fursini           #+#    #+#             */
/*   Updated: 2024/05/20 17:33:09 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	heredoc(t_io_redir *io)
{
	int		fd;

	fd = open(io->input, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		g_exit_status = 1;
		print_error(strerror(errno));
		return (false);
	}
	read_heredoc(fd, io);
	close(fd);
	return (true);
}

void	read_heredoc(int fd, t_io_redir *io)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = readline("> ");
		if (!heredoc_line(line, io))
			break ;
		ft_putendl_fd(line, fd);
		check_free(line);
	}
	check_free(line);
}

bool	heredoc_line(char *line, t_io_redir *io)
{
	if (!line)
	{
		ft_putstr_fd("minishell: warning: ", 2);
		ft_putendl_fd ("here-document delimited by end-of-file(wanted `')", 2);
		return (false);
	}
	if (ft_strcmp(line, io->heredoc) == 0)
		return (false);
	return (true);
}
