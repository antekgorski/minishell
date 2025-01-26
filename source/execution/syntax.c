/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:23:56 by agorski           #+#    #+#             */
/*   Updated: 2025/01/26 14:00:16 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_syntax_error(const char *token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd((char *)token, 2);
	ft_putstr_fd("'\n", 2);
}

static int	validate_redirection_token(t_redir *redir)
{
	if (!redir->filename)
	{
		if (redir->type == APPEND && redir->next && redir->next->type == OREDIR)
		{
			print_syntax_error(">>");
			return (0);
		}
		if (redir->type == OREDIR && redir->next && redir->next->type == OREDIR)
		{
			print_syntax_error(">");
			return (0);
		}
		print_syntax_error("newline");
		return (0);
	}
	return (1);
}

int	validate_redirections(t_redir *redirs)
{
	t_redir	*temp;

	temp = redirs;
	while (temp)
	{
		if (!validate_redirection_token(temp))
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	validate_pipeline(t_cmd *cmds, t_minishell *minishell)
{
	t_cmd	*temp;

	if (!cmds || (!cmds->argv && cmds->next))
	{
		print_syntax_error("|");
		minishell->f_signal = 2;
		return (0);
	}
	temp = cmds;
	while (temp)
	{
		if (!validate_redirections(temp->redirs))
			return (0);
		if (!temp->argv && temp->next)
		{
			print_syntax_error("|");
			minishell->f_signal = 2;
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}
