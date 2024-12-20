/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexter_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:47:40 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 19:02:03 by agorski          ###   ########.fr       */
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
	minishell->lexter_tab = ft_addline(minishell, temp, SQUOTE);
	return (i + 1);
}
int	ft_qdolar(char *q_line, t_minishell *minishell)
{
// like ft_dolar
}

int	ft_qtext(char *q_line, t_minishell *minishell)
{
// like ft_cmd
}

void	ft_d_roll(char **temp_arg, t_minishell *minishell)
{
	char	*q_line;

	q_line = *temp_arg;
	while (*q_line)
	{
		if (ft_strchr(SYMBOLS, *q_line))
		{
			if (*q_line == ' ' || *q_line == '\t')
				q_line++;
			if (*q_line == '$')
				q_line += ft_qdolar(q_line, minishell);
		}
		else
			q_line += ft_qtext(q_line, minishell);
	}
}

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
	ft_d_roll(&temp, minishell);
	minishell->lexter_tab = ft_addline(minishell, temp, DQUOTE);
	return (i + 1);
}
