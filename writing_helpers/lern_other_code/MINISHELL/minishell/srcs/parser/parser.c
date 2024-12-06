/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:54:30 by fursini           #+#    #+#             */
/*   Updated: 2024/05/20 17:33:21 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	parser(t_minishell *shell)
{
	handle_dollar(shell);
	remove_empty_tokens(shell);
	give_token_type(shell);
	remove_quotes(shell);
	if (check_error_token_list(shell))
		return (false);
	create_command_list(shell);
	return (true);
}

void	create_command_list(t_minishell *shell)
{
	t_token	*tmp;

	tmp = shell->token_list;
	add_command(shell);
	g_exit_status = 0;
	while (tmp)
	{
		if (tmp->type == COMMAND || tmp->type == ARGUMENT)
			cmd_word(shell, &tmp);
		else if (tmp->type == REDIR_IN)
			cmd_redir_in(shell, &tmp);
		else if (tmp->type == REDIR_OUT)
			cmd_redir_out(shell, &tmp, REDIR_OUT);
		else if (tmp->type == HEREDOC)
			cmd_redir_heredoc(shell, &tmp);
		else if (tmp->type == APPEND)
			cmd_redir_out(shell, &tmp, APPEND);
		else if (tmp->type == PIPE)
			cmd_pipe(shell, &tmp);
		else if (!tmp)
			break ;
	}
}

void	add_command(t_minishell *shell)
{
	t_command	*new;

	new = shell->command;
	if (!new)
	{
		shell->command = init_command();
		return ;
	}
	while (new->next)
		new = new->next;
	new->next = init_command();
	new->next->prev = new;
}
