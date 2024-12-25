/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_dolar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:53:41 by agorski           #+#    #+#             */
/*   Updated: 2024/12/25 13:21:58 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dolar_case1(t_t *t, t_minishell *minishell)
{
	char	*temp;

	t->temp = ft_itoa(minishell->f_signal);
	temp = ft_strjoin(t->result, t->temp);
	free(t->result);
	t->result = NULL;
	free(t->temp);
	t->temp = NULL;
	t->result = temp;
	t->end += 2;
	t->start = t->end;
}

void	ft_dolar_case2(t_t *t)
{
	char	*temp;

	t->end += 2;
	t->temp = ft_strdup("$$");
	temp = ft_strjoin(t->result, t->temp);
	free(t->result);
	t->result = NULL;
	free(t->temp);
	t->temp = NULL;
	t->result = temp;
	t->start = t->end;
}

void	ft_dolar_case3(t_t *t)
{
	char	*temp;

	t->end++;
	t->temp = ft_strdup("$");
	temp = ft_strjoin(t->result, t->temp);
	free(t->result);
	t->result = NULL;
	free(t->temp);
	t->temp = NULL;
	t->result = temp;
	t->start = t->end;
}

void	ft_dolar_case4(t_t *t, char *line, t_minishell *minishell)
{
	char	*temp;

	t->end++;
	t->start = t->end;
	while (line[t->end] && !strchr(SYMBOLS_R, line[t->end]))
		t->end++;
	t->temp = ft_substr(line, t->start, (t->end - t->start));
	t->env = ft_get_env(minishell->m_env, t->temp);
	free(t->temp);
	temp = ft_strjoin(t->result, t->env);
	free(t->result);
	t->result = NULL;
	t->env = NULL;
	t->result = temp;
	t->start = t->end;
}

void	ft_dolar_case5(t_t *t, char *line)
{
	char	*temp;

	t->start = t->end;
	while (line[t->end] && !strchr(SYMBOLS_R, line[t->end]))
		t->end++;
	t->temp = ft_substr(line, t->start, t->end - t->start);
	temp = ft_strjoin(t->result, t->temp);
	free(t->temp);
	t->temp = NULL;
	free(t->result);
	t->result = NULL;
	t->result = temp;
	t->start = t->end;
}
