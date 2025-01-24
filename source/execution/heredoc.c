/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/24 20:11:44 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_heredoc(const char *delimiter)
{
	char	*line;
	int		tmp_fd;

	tmp_fd = open("/tmp/heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_fd == -1)
		ft_panic("open", EXIT_FAILURE);
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(tmp_fd, line, ft_strlen(line));
		write(tmp_fd, "\n", 1);
		free(line);
	}
	close(tmp_fd);
	tmp_fd = open("/tmp/heredoc_tmp", O_RDONLY);
	if (tmp_fd == -1)
		ft_panic("open", EXIT_FAILURE);
	unlink("/tmp/heredoc_tmp");
	return (tmp_fd);
}
