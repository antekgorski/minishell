/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/25 10:43:02 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	is_builtin(t_cmd *cmd)
{
	if (!cmd->argv || !cmd->argv[0])
		return (0);
	if (!ft_strcmp(cmd->argv[0], "echo"))
		return (1);
	if (!ft_strcmp(cmd->argv[0], "cd"))
		return (1);
	if (!ft_strcmp(cmd->argv[0], "pwd"))
		return (1);
	if (!ft_strcmp(cmd->argv[0], "export"))
		return (1);
	if (!ft_strcmp(cmd->argv[0], "unset"))
		return (1);
	if (!ft_strcmp(cmd->argv[0], "env"))
		return (1);
	if (!ft_strcmp(cmd->argv[0], "exit"))
		return (1);
	return (0);
}

void	handle_heredocs(t_redir *redirs)
{
	t_redir	*temp;
	int		fd;

	temp = redirs;
	while (temp)
	{
		if (temp->type == HERDOC)
		{
			fd = handle_heredoc(temp->filename);
			if (fd < 0)
				ft_panic("minishell: ", EXIT_FAILURE);
			dup2(fd, STDIN_FILENO);
			close(fd);
		}
		temp = temp->next;
	}
}

void	handle_other_redirections(t_redir *redirs)
{
	t_redir	*temp;
	int		fd;

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
