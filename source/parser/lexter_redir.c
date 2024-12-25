/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexter_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:59:04 by agorski           #+#    #+#             */
/*   Updated: 2024/12/25 13:05:21 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pipe(t_minishell *minishell)
{
	char	*temp_arg;

	temp_arg = ft_strdup("|");
	minishell->lexter_tab = ft_addline(minishell, temp_arg, PIPE);
	temp_arg = NULL;
	return (1);
}

int	ft_oredir(char *temp_line, t_minishell *minishell)
{
	char	*temp_arg;

	if (*(temp_line + 1) == '>')
	{
		temp_arg = ft_strdup(">>");
		minishell->lexter_tab = ft_addline(minishell, temp_arg, APPEND);
		temp_arg = NULL;
		return (2);
	}
	else
		temp_arg = ft_strdup(">");
	minishell->lexter_tab = ft_addline(minishell, temp_arg, OREDIR);
	temp_arg = NULL;
	return (1);
}

int	ft_iredir(char *temp_line, t_minishell *minishell)
{
	char	*temp_arg;

	if (*(temp_line + 1) == '<')
	{
		temp_arg = ft_strdup("<<");
		minishell->lexter_tab = ft_addline(minishell, temp_arg, HERDOC);
		temp_arg = NULL;
		return (2);
	}
	else
		temp_arg = ft_strdup("<");
	minishell->lexter_tab = ft_addline(minishell, temp_arg, IREDIR);
	temp_arg = NULL;
	return (1);
}
