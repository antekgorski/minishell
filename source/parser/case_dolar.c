/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_dolar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:53:41 by agorski           #+#    #+#             */
/*   Updated: 2024/12/23 23:23:23 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_case1(t_t *t, t_minishell *minishell)
{
	t->temp = ft_itoa(minishell->f_signal);
	t->result = ft_strjoin(t->result, t->temp);
	free(t->temp);
	t->end += 2;
	t->start = t->end;
}

void	ft_case2(t_t *t)
{
	t->end += 2;
	t->temp = ft_strdup("$$");
	t->result = ft_strjoin(t->result, t->temp);
	free(t->temp);
	t->start = t->end;
}

void	ft_case3(t_t *t)
{
	t->end++;
	t->temp = ft_strdup("$");
	t->result = ft_strjoin(t->result, t->temp);
	free(t->temp);
	t->start = t->end;
}

void	ft_case4(t_t *t, char *line, t_minishell *minishell)
{
	t->end++;
	t->start = t->end;
	while (line[t->end] && !strchr(SYMBOLS_R, line[t->end]))
		t->end++;
	t->temp = ft_substr(line, t->start, (t->end - t->start));
	t->env = ft_get_env(minishell->m_env, t->temp);
	free(t->temp);
	t->result = ft_strjoin(t->result, t->env);
	free(t->env);
	t->start = t->end;
}

void	ft_case5(t_t *t, char *line)
{
	t->start = t->end;
	while (line[t->end] && !strchr(SYMBOLS_R, line[t->end]))
		t->end++;
	t->temp = ft_substr(line, t->start, t->end - t->start);
	t->result = ft_strjoin(t->result, t->temp);
	free(t->temp);
	t->start = t->end;
}
