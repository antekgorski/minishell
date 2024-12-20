/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexter_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:47:40 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 23:57:14 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_squote(char *temp_line, t_minishell *minishell)
{
	int		i;
	char	*temp;

	i = 1;
	while (temp_line[i] && temp_line[i] != '\'')
		i++;
	temp = ft_substr(temp_line, 1, i - 1);
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

void	ft_d_roll(char **in_d_quote, t_minishell *minishell)
{
	char	*temp;
	char	*result;
	char	*q_line;
	int		s;
	int		m;

	s = 0;
	m = 0;
	q_line = *in_d_quote;
	while (q_line[m])
	{
		if (q_line[m] == '$')
		{
			temp = ft_substr(q_line, s, m - s);
			result = ft_strjoin(result, temp);
			free(temp);
			s = m;
			while (q_line[m] && !ft_strchr("' ''\t''$'", q_line[m]))
				m++;
			temp = ft_substr(q_line, s, m - s);
			result = ft_strjoin(result, ft_get_env(minishell->m_env, temp));
			free(temp);
		}
		if (q_line[m] != '$')
			m++;
	}
	temp = ft_substr(q_line, s, m - s);
	result = ft_strjoin(result, temp);
	free(temp);
}

int	ft_dquote(char *temp_line, t_minishell *minishell)
{
	int		i;
	char	*temp;

	i = 1;
	while (temp_line[i] && temp_line[i] != '\"')
		i++;
	temp = ft_substr(temp_line, 1, i - 1);
	ft_d_roll(&temp, minishell);
	minishell->lexter_tab = ft_addline(minishell, temp, DQUOTE);
	return (i + 1);
}
