/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rollup_dolar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:51:04 by agorski           #+#    #+#             */
/*   Updated: 2024/12/21 23:27:06 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_t(t_t *t)
{
	t->result = NULL;
	t->temp = NULL;
	t->temp_env = NULL;
	t->var_name = NULL;
	t->var_value = NULL;
	t->literal = NULL;
	t->start = 0;
	t->end = 0;
}

static void	ft_else(t_t *t, char *line)
{
	t->end = t->start;
	while (line[t->end] && line[t->end] != '$')
		t->end++;
	t->literal = ft_substr(line, t->start, t->end - t->start);
	t->temp = ft_strjoin(t->result, t->literal);
	free(t->result);
	free(t->literal);
	t->result = t->temp;
	t->start = t->end;
}

static void	ft_if(t_t *t, char *line, t_minishell *minishell)
{
	{
		if (line[t->start + 1] == '$')
			t->start += 2;
		else
			t->start++;
		t->end = t->start;
		while (line[t->end] && !ft_strchr("'$'' ''\t'", line[t->end]))
			t->end++;
		t->var_name = ft_substr(line, t->start, t->end - t->start);
		t->temp_env = ft_get_env(minishell->m_env, t->var_name);
		free(t->var_name);
		t->var_value = ft_strdup(t->temp_env);
		if (t->var_value)
		{
			t->temp = ft_strjoin(t->result, t->var_value);
			if (t->result)
				free(t->result);
			t->result = t->temp;
		}
		t->start = t->end;
	}
}

char	*ft_d_roll(char *line, t_minishell *minishell)
{
	t_t	t;

	ft_init_t(&t);
	while (line[t.start])
	{
		if (line[t.start] == '$')
			ft_if(&t, line, minishell);
		else
			ft_else(&t, line);
	}
	return (t.result);
}