/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:23:56 by agorski           #+#    #+#             */
/*   Updated: 2025/01/27 14:03:35 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_syntax_error(const char *token, t_minishell *minishell)
{
	minishell->f_signal = 2;
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd((char *)token, 2);
	ft_putstr_fd("'\n", 2);
}

int	validate_pipeline(t_cmd *cmds, t_minishell *minishell)
{
	t_cmd	*temp;

	if (!cmds)
	{
		print_syntax_error("|", minishell);
		return (0);
	}
	temp = cmds;
	while (temp)
	{
		if (!temp->argv && !temp->redirs && !temp->next)
		{
			print_syntax_error("|", minishell);
			return (0);
		}
		if (temp->next && !temp->next->argv && !temp->next->redirs)
		{
			print_syntax_error("|", minishell);
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}
