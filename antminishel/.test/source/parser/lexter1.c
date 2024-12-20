/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexter1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:47:40 by agorski           #+#    #+#             */
/*   Updated: 2024/12/17 10:11:54 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_squote(char *temp_line, t_minishell *minishell)
{
	int		i;
	char	*temp_arg;
	char	*temp;

	i = 1;
	while (temp_line[i] && temp_line[i] != '\'')
		i++;
	temp_arg = ft_substr(temp_line, 1, i - 1);
	temp = ft_strtrim(temp_arg, " \t");
	free(temp_arg);
	minishell->lexter_tab = ft_addline(minishell->lexter_tab, temp);
	return (i + 1);
}

// need to add $ and check for it
int	ft_dquote(char *temp_line, t_minishell *minishell)
{
	int		i;
	char	*temp_arg;
	char	*temp;

	i = 1;
	while (temp_line[i] && temp_line[i] != '\"')
		i++;
	temp_arg = ft_substr(temp_line, 1, i - 1);
	temp = ft_strtrim(temp_arg, " \t");
	free(temp_arg);
	minishell->lexter_tab = ft_addline(minishell->lexter_tab, temp);
	return (i + 1);
}

int	ft_dolar(char *temp_line, t_minishell *minishell)
{
	int		i;
	char	*temp_arg;
	char	*temp;

	i = 1;
	while (temp_line[i] && !ft_strchr(SYMBOLS, temp_line[i]))
		i++;
	temp_arg = ft_substr(temp_line, 0, i);
	temp = ft_strtrim(temp_arg, " \t");
	free(temp_arg);
	minishell->lexter_tab = ft_addline(minishell->lexter_tab, temp);
	return (i);
}

int	ft_iredir(char *temp_line, t_minishell *minishell)
{
	char	*temp_arg;

	if (*(temp_line + 1) == '<')
	{
		temp_arg = ft_strdup("<<");
		minishell->lexter_tab = ft_addline(minishell->lexter_tab, temp_arg);
		return (2);
	}
	else
		temp_arg = ft_strdup("<");
	minishell->lexter_tab = ft_addline(minishell->lexter_tab, temp_arg);
	return (1);
}

int	ft_oredir(char *temp_line, t_minishell *minishell)
{
	char	*temp_arg;

	if (*(temp_line + 1) == '>')
	{
		temp_arg = ft_strdup(">>");
		minishell->lexter_tab = ft_addline(minishell->lexter_tab, temp_arg);
		return (2);
	}
	else
		temp_arg = ft_strdup(">");
	minishell->lexter_tab = ft_addline(minishell->lexter_tab, temp_arg);
	return (1);
}
