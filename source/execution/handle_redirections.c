/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/27 12:32:51 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	handle_final_heredoc(int last_fd)
{
	if (last_fd != -1)
	{
		dup2(last_fd, STDIN_FILENO);
		close(last_fd);
	}
}

static int	process_heredoc(t_redir *temp, int *last_fd)
{
	int	fd;

	if (*last_fd != -1)
		close(*last_fd);
	fd = handle_heredoc(temp->filename);
	if (fd < 0)
		return (-1);
	*last_fd = fd;
	return (0);
}

void	handle_heredocs(t_redir *redirs)
{
	t_redir	*temp;
	int		last_heredoc_fd;

	temp = redirs;
	last_heredoc_fd = -1;
	while (temp)
	{
		if (temp->type == HERDOC)
		{
			if (process_heredoc(temp, &last_heredoc_fd) < 0)
			{
				ft_putstr_fd("minishell: heredoc error\n", 2);
				exit(EXIT_FAILURE);
			}
		}
		temp = temp->next;
	}
	handle_final_heredoc(last_heredoc_fd);
}

void	handle_other_redirections(t_redir *redirs)
{
	t_redir	*temp;
	int		fd;

	fd = -1;
	temp = redirs;
	while (temp)
	{
		if (temp->type == IREDIR)
			fd = open(temp->filename, O_RDONLY);
		else if (temp->type == OREDIR)
			fd = open(temp->filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (temp->type == APPEND)
			fd = open(temp->filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd < 0)
			ft_panic("minishell: ", EXIT_FAILURE);
		if (temp->type == IREDIR)
			dup2(fd, STDIN_FILENO);
		else
			dup2(fd, STDOUT_FILENO);
		close(fd);
		temp = temp->next;
	}
}

void	handle_redirections(t_redir *redirs)
{
	handle_heredocs(redirs);
	handle_other_redirections(redirs);
}
