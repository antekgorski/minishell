/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:36:33 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/02 11:49:27 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_get_next_token(t_content *minishell)
{
	minishell->free_token = minishell->free_token->next;
}

t_io_type	ft_get_io_type(t_token_type type)
{
	if (type == T_LESS)
		return (E_IN);
	if (type == T_GREAT)
		return (E_OUT);
	if (type == T_DLESS)
		return (E_HEREDOC);
	return (E_APPEND);
}

int	ft_is_redirector(t_token_type type)
{
	if (type == T_LESS || type == T_GREAT || type == T_DLESS
		|| type == T_DGREAT)
		return (1);
	return (0);
}

bool	check_for_pipe_and_token(t_content *minishell)
{
	if (minishell->free_token)
		if (minishell->free_token->type == T_PIPE)
			return (true);
	return (false);
}
