/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bilder_tool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:36:32 by agorski           #+#    #+#             */
/*   Updated: 2025/01/22 19:28:05 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

bool	ft_check_redir(t_list *token)
{
	if (*(t_token*)token->content == IREDIR || *(t_token*)token->content == OREDIR
		|| *(t_token*)token->content == APPEND
		|| *(t_token*)token->content == HERDOC)
		return (true);
	return (false);
}

void	ft_t_cmd_init(t_cmd *cmd)
{
	cmd->argv = NULL;
	cmd->redirs = NULL;
	cmd->next = NULL;
}

void	ft_cb_init(t_cb *cb, t_minishell *minishell)
{
	cb->token = minishell->token_list;
	cb->cmds = ft_new_cmd();
	cb->c_cmd = cb->cmds;
	cb->i = 0;
}
