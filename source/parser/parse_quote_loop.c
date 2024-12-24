/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:05:22 by agorski           #+#    #+#             */
/*   Updated: 2024/12/24 14:08:26 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_case_lp(int *p, int *r)
{
	*p += 1;
	*r *= -1;
}

static void	ft_case_ln(int *p, int *r)
{
	*p += -1;
	*r *= -1;
}

void	ft_quote_loop(char *line, t_q *q)
{
	while (line[q->i])
	{
		q->i++;
		if (line[q->i] == '\"' && q->d == 0 && q->s == 0)
		{
			ft_case_lp(&q->d, &q->result);
			continue ;
		}
		if (line[q->i] == '\"' && q->d == 1 && q->s == 0)
		{
			ft_case_ln(&q->d, &q->result);
			continue ;
		}
		if (line[q->i] == '\'' && q->s == 0 && q->d == 0)
		{
			ft_case_lp(&q->s, &q->result);
			continue ;
		}
		if (line[q->i] == '\'' && q->s == 1 && q->d == 0)
		{
			ft_case_ln(&q->s, &q->result);
			continue ;
		}
	}
}
