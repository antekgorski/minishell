/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexter0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:30:40 by agorski           #+#    #+#             */
/*   Updated: 2024/12/15 22:07:35 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_addline(char **argv, char *line)
{
	char	**new_argv;
	int		i;

	i = 0;
	while (argv && argv[i])
		i++;
	new_argv = ft_calloc(sizeof(char *) * (i + 2), 1);
	if (new_argv == NULL)
		ft_panic("malloc", 1);
	i = 0;
	while (argv && argv[i])
	{
		new_argv[i] = argv[i];
		i++;
	}
	new_argv[i] = line;
	new_argv[i + 1] = NULL;
	return (new_argv);
}

int	ft_comend(char *temp_line, t_minishell *minishell)
{
	char	*temp_arg;
	int		i;

	i = 0;
	while (temp_line[i] && !ft_strchr(SYMBOLS, temp_line[i]))
		i++;
	temp_arg = ft_substr(temp_line, 0, i);
	minishell->lexter_tab = ft_addline(minishell->lexter_tab, temp_arg);
	return (i);
}

int	ft_pipe(t_minishell *minishell)
{
	minishell->lexter_tab = ft_addline(minishell->lexter_tab, "|");
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
