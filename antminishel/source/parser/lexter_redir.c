/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexter_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:59:04 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:10:11 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pipe(t_minishell *minishell)
{
	char	*temp_arg;

	temp_arg = ft_strdup("|");
	minishell->lexter_tab = ft_addline(minishell, temp_arg, PIPE);
	return (1);
}

int	ft_oredir(char *temp_line, t_minishell *minishell)
{
	char	*temp_arg;

	if (*(temp_line + 1) == '>')
	{
		temp_arg = ft_strdup(">>");
		minishell->lexter_tab = ft_addline(minishell, temp_arg, APPEND);
		return (2);
	}
	else
		temp_arg = ft_strdup(">");
	minishell->lexter_tab = ft_addline(minishell, temp_arg, OREDIR);
	return (1);
}

int	ft_iredir(char *temp_line, t_minishell *minishell)
{
	char	*temp_arg;

	if (*(temp_line + 1) == '<')
	{
		temp_arg = ft_strdup("<<");
		minishell->lexter_tab = ft_addline(minishell, temp_arg, HERDOC);
		return (2);
	}
	else
		temp_arg = ft_strdup("<");
	minishell->lexter_tab = ft_addline(minishell, temp_arg, IREDIR);
	return (1);
}
