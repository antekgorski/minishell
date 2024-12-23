/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rollup_dolar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:51:04 by agorski           #+#    #+#             */
/*   Updated: 2024/12/23 21:00:04 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_dolar(t_t *dolar)
{
	dolar->start = 0;
	dolar->end = 0;
	dolar->temp = NULL;
	dolar->result = NULL;
	dolar->env = NULL;
}

char	*ft_d_roll(char *line, t_minishell *minishell)
{
	t_t	t;

	ft_init_dolar(&t);
	while (line[t.end])
	{
		if (line[t.end] == '$' && line[t.end + 1] == '\0')
		{
			t.end++;
			t.temp = ft_strdup("$");
			t.result = ft_strjoin(t.result, t.temp);
			free(t.temp);
			t.start = t.end;
		}
		if (line[t.end] == '$' && line[t.end + 1] == '?')
		{
			t.temp = ft_itoa(minishell->f_signal);
			t.result = ft_strjoin(t.result, t.temp);
			free(t.temp);
			t.end += 2;
			t.start = t.end;
		}
		if (line[t.end] == '$' && line[t.end + 1] == '$')
		{
			t.end += 2;
			t.temp = ft_strdup("$$");
			t.result = ft_strjoin(t.result, t.temp);
			free(t.temp);
			t.start = t.end;
		}
		if (line[t.end] == '$' && !strchr(SYMBOLS_S, line[t.end + 1]))
		{
			t.end++;
			t.start = t.end;
			while (line[t.end] && !strchr(SYMBOLS_R, line[t.end]))
				t.end++;
			t.temp = ft_substr(line, t.start, (t.end - t.start));
			t.env = ft_get_env(minishell->m_env, t.temp);
			free(t.temp);
			t.result = ft_strjoin(t.result, t.env);
			free(t.env);
			t.start = t.end;
		}
		if (line[t.end] != '$' && line[t.end] != '\0')
		{
			t.start = t.end;
			while (line[t.end] && !strchr(SYMBOLS_R, line[t.end]))
				t.end++;
			t.temp = ft_substr(line, t.start, t.end);
			t.result = ft_strjoin(t.result, t.temp);
			free(t.temp);
		}
	}
	return (t.result);
}
