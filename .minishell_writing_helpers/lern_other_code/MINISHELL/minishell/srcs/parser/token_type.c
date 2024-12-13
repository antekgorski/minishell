/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:56:56 by fursini           #+#    #+#             */
/*   Updated: 2024/05/20 17:33:26 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	give_token_type(t_minishell *shell)
{
	t_token	*tmp;

	tmp = shell->token_list;
	while (tmp)
	{
		if (ft_strcmp(tmp->str, ">") == 0)
			tmp->type = REDIR_OUT;
		else if (ft_strcmp(tmp->str, "<") == 0)
			tmp->type = REDIR_IN;
		else if (ft_strcmp(tmp->str, ">>") == 0)
			tmp->type = APPEND;
		else if (ft_strcmp(tmp->str, "<<") == 0)
			tmp->type = HEREDOC;
		else if (ft_strcmp(tmp->str, "|") == 0)
			tmp->type = PIPE;
		else if (ft_strcmp(tmp->str, "") == 0)
			tmp->type = EMPTY;
		else if (token_is_command(tmp))
			tmp->type = COMMAND;
		else
			tmp->type = ARGUMENT;
		tmp = tmp->next;
	}
}

bool	token_is_command(t_token *token)
{
	if (token->prev == NULL || token->prev->type == PIPE)
		return (true);
	else if (token->prev->prev && token_is_redir(token->prev->prev->type)
		&& (!token->prev->prev->prev || token->prev->prev->prev->type == PIPE))
		return (true);
	return (false);
}

bool	token_is_redir(int type)
{
	if (type == REDIR_OUT || type == REDIR_IN
		|| type == APPEND || type == HEREDOC)
		return (true);
	return (false);
}
