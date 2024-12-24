/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rollup_dolar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:51:04 by agorski           #+#    #+#             */
/*   Updated: 2024/12/25 00:22:39 by agorski          ###   ########.fr       */
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
		if (line[t.end] == '$' && line[t.end + 1] == '?')
			ft_dolar_case1(&t, minishell);
		if (line[t.end] == '$' && line[t.end + 1] == '$')
			ft_dolar_case2(&t);
		if (line[t.end] == '$' && line[t.end + 1] == '\0')
			ft_dolar_case3(&t);
		else if (line[t.end] == '$' && !strchr(SYMBOLS_S, line[t.end + 1]))
			ft_dolar_case4(&t, line, minishell);
		if (line[t.end] != '$' && line[t.end])
		{
			ft_dolar_case5(&t, line);
			if (line[t.end] == '\0')
				break ;
		}
		if (line[t.end] == ' ' || line[t.end] == '\t')
			t.end++;
	}
	return (t.result);
}
