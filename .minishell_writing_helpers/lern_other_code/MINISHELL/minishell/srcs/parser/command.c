/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:48:45 by fursini           #+#    #+#             */
/*   Updated: 2024/05/20 17:33:12 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_word(t_minishell *shell, t_token **token)
{
	t_command	*cmd;
	t_token		*tmp;

	cmd = shell->command;
	tmp = *token;
	while (cmd->next)
		cmd = cmd->next;
	while (tmp && (tmp->type == COMMAND || tmp->type == ARGUMENT))
	{
		if (tmp->type == COMMAND)
		{
			cmd->name = ft_strdup(tmp->str);
			cmd->args = add_arg(cmd->args, tmp->str);
		}
		else if (tmp->prev && !token_is_redir(tmp->prev->type))
			cmd->args = add_arg(cmd->args, tmp->str);
		tmp = tmp->next;
	}
	*token = tmp;
}

void	cmd_redir_in(t_minishell *shell, t_token **token)
{
	t_command	*cmd;
	t_token		*tmp;

	cmd = shell->command;
	tmp = *token;
	while (cmd->next)
		cmd = cmd->next;
	init_io(cmd);
	open_input(cmd->io_redir, tmp->next->str);
	*token = tmp->next;
	if (tmp->next->next)
		*token = tmp->next->next;
}

void	cmd_redir_out(t_minishell *shell, t_token **token, int type)
{
	t_command	*cmd;
	t_token		*tmp;

	cmd = shell->command;
	tmp = *token;
	while (cmd->next)
		cmd = cmd->next;
	init_io(cmd);
	if (tmp->next)
		open_output(cmd->io_redir, tmp->next->str, type);
	*token = tmp->next;
	if (tmp->next->next)
		*token = tmp->next->next;
}

void	cmd_redir_heredoc(t_minishell *shell, t_token **token)
{
	t_command	*cmd;
	t_token		*tmp;
	t_io_redir	*io;

	cmd = shell->command;
	tmp = *token;
	while (cmd->next)
		cmd = cmd->next;
	init_io(cmd);
	io = cmd->io_redir;
	if (!delete_file(io, true))
		return ;
	io->heredoc = ft_strdup(tmp->next->str);
	io->input = ft_strdup("/tmp/heredoc");
	if (heredoc(io))
		io->fd_input = open(io->input, O_RDONLY);
	else
		io->fd_input = -1;
	*token = tmp->next;
	if (tmp->next->next)
		*token = tmp->next->next;
}

void	cmd_pipe(t_minishell *shell, t_token **token)
{
	t_command	*cmd;

	cmd = shell->command;
	while (cmd->next)
		cmd = cmd->next;
	cmd->pipe = true;
	add_command(shell);
	*token = (*token)->next;
}
