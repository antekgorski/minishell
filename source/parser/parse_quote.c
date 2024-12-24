/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:43:39 by agorski           #+#    #+#             */
/*   Updated: 2024/12/24 14:08:44 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_case_start(char *line, t_q *q)
{
	if (line[q->i] == '\"')
	{
		q->d += 1;
		q->result *= -1;
	}
	if (line[q->i] == '\'')
	{
		q->s += 1;
		q->result *= -1;
	}
}

static void	init(t_q *q)
{
	q->result = 1;
	q->i = 0;
	q->d = 0;
	q->s = 0;
}

int	check_quote(char *line)
{
	t_q	q;

	init(&q);
	ft_case_start(line, &q);
	ft_quote_loop(line, &q);
	if (q.result == -1)
	{
		printf("Unmatched quote. Please check your input.\n");
		return (1);
	}
	else
		return (0);
}
