/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexter0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:30:40 by agorski           #+#    #+#             */
/*   Updated: 2024/12/19 20:46:23 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// add line to the lexter_tab
// if the lexter_tab is NULL it will create a new one
// if the lexter_tab is not NULL it will add a new line to it
// and then it will free the old one
// and return the new one

char	**ft_addline(t_minishell *minishell, char *line, t_token token)
{
	char	**new_argv;
	int		i;

	i = 0;
	while (minishell->lexter_tab && minishell->lexter_tab[i])
		i++;
	new_argv = ft_calloc(sizeof(char *) * (i + 2), 1);
	if (new_argv == NULL)
		ft_panic("malloc", 1);
	i = 0;
	while (minishell->lexter_tab && minishell->lexter_tab[i])
	{
		new_argv[i] = minishell->lexter_tab[i];
		i++;
	}
	new_argv[i] = line;
	ft_get_token(token, minishell);
	new_argv[i + 1] = NULL;
	if (minishell->lexter_tab)
		free(minishell->lexter_tab);
	return (new_argv);
}

// single quote
// it will add the line to the lexter_tab

int	ft_comend(char *temp_line, t_minishell *minishell)
{
	char	*temp_arg;
	int		i;

	i = 0;
	while (temp_line[i] && !ft_strchr(SYMBOLS, temp_line[i]))
		i++;
	temp_arg = ft_substr(temp_line, 0, i);
	minishell->lexter_tab = ft_addline(minishell, temp_arg, CMD);
	return (i);
}

int	ft_pipe(t_minishell *minishell)
{
	char	*temp_arg;

	temp_arg = ft_strdup("|");
	minishell->lexter_tab = ft_addline(minishell, temp_arg, PIPE);
	return (1);
}

void	ft_lexter(t_minishell *minishell)
{
	char	*temp_line;

	temp_line = minishell->line;
	while (*temp_line)
	{
		if (ft_strchr(SYMBOLS, *temp_line))
		{
			if (*temp_line == ' ' || *temp_line == '\t')
				temp_line++;
			if (*temp_line == '\'')
				temp_line += ft_squote(temp_line, minishell);
			if (*temp_line == '\"')
				temp_line += ft_dquote(temp_line, minishell);
			if (*temp_line == '$')
				temp_line += ft_dolar(temp_line, minishell);
			if (*temp_line == '|')
				temp_line += ft_pipe(minishell);
			if (*temp_line == '<')
				temp_line += ft_iredir(temp_line, minishell);
			if (*temp_line == '>')
				temp_line += ft_oredir(temp_line, minishell);
		}
		else
			temp_line += ft_comend(temp_line, minishell);
	}
}
