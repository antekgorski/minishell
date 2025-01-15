/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rollup_dolar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:51:04 by agorski           #+#    #+#             */
/*   Updated: 2025/01/14 17:57:03 by prutkows         ###   ########.fr       */
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

static void	ft_case_space(t_t *t, char *line)
{
	char	*temp;

	t->start = t->end;
	while (ft_strchr(SYM_E, line[t->end]))
		t->end++;
	t->temp = ft_substr(line, t->start, (t->end - t->start));
	temp = ft_strjoin(t->result, t->temp);
	free(t->temp);
	t->temp = NULL;
	free(t->result);
	t->result = NULL;
	t->result = temp;
	t->start = t->end;
}

char	*ft_d_roll(char *line, t_minishell *minishell)
{
	t_t	t;

	ft_init_dolar(&t);
	while (line[t.end])
	{
		if (line[t.end] == '$' && line[t.end + 1] == '?')
			ft_dolar_case1(&t, minishell);
		if (line[t.end] == '$' && line[t.end + 1] == '$')
			ft_dolar_case2(&t);
		if (line[t.end] == '$' && line[t.end + 1] == '\0')
			ft_dolar_case3(&t);
		else if (line[t.end] == '$' && !ft_strchr(SYMBOLS_S, line[t.end + 1]))
			ft_dolar_case4(&t, line, minishell);
		if (line[t.end] != '$' && line[t.end] && !ft_strchr(SYM_E, line[t.end]))
		{
			ft_dolar_case5(&t, line);
			if (line[t.end] == '\0')
				break ;
		}
		if (ft_strchr(SYM_E, line[t.end]))
			ft_case_space(&t, line);
	}
	return (t.result);
}
