/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 05:35:29 by agorski           #+#    #+#             */
/*   Updated: 2024/12/24 14:05:42 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct s_q
// {
// 	int		result;
// 	int		i;
// 	int		d;
// 	int		s;
// }			t_q;

// void	init(t_q *q)
// {
// 	q->result = 1;
// 	q->i = 0;
// 	q->d = 0;
// 	q->s = 0;
// }

// static void	ft_case_start(char *line, t_q *q)
// {
// 	if (line[q->i] == '\"')
// 	{
// 		q->d += 1;
// 		q->result *= -1;
// 	}
// 	if (line[q->i] == '\'')
// 	{
// 		q->s += 1;
// 		q->result *= -1;
// 	}
// }

// static void	ft_case_lp(int *p, int *r)
// {
// 	*p += 1;
// 	*r *= -1;
// }

// static void	ft_case_ln(int *p, int *r)
// {
// 	*p += -1;
// 	*r *= -1;
// }

// static void	ft_case_loop(char *line, t_q *q)
// {
// 	while (line[q->i])
// 	{
// 		q->i++;
// 		if (line[q->i] == '\"' && q->d == 0 && q->s == 0)
// 		{
// 			ft_case_lp(&q->d, &q->result);
// 			continue ;
// 		}
// 		if (line[q->i] == '\"' && q->d == 1 && q->s == 0)
// 		{
// 			ft_case_ln(&q->d, &q->result);
// 			continue ;
// 		}
// 		if (line[q->i] == '\'' && q->s == 0 && q->d == 0)
// 		{
// 			ft_case_lp(&q->s, &q->result);
// 			continue ;
// 		}
// 		if (line[q->i] == '\'' && q->s == 1 && q->d == 0)
// 		{
// 			ft_case_ln(&q->s, &q->result);
// 			continue ;
// 		}
// 	}
// }

// int	test_quote(char *line)
// {
// 	t_q	q;

// 	init(&q);
// 	ft_case_start(line, &q);
// 	ft_case_loop(line, &q);
// 	if (q.result == -1)
// 	{
// 		printf("Unmatched quote. Please check your input.\n");
// 		return (1);
// 	}
// 	else
// 		return (0);
// }

int	main(void)
{
	printf("test quore 1: ");
	printf("%d", test_quote("\"te\'st\"\'\""));
	printf("\n");
	printf("test quore -1: ");
	printf("%d", test_quote("\'te\'st\"\'"));
	printf("\n");
	printf("test quore -1: ");
	printf("%d", test_quote("\'te\'st\"\'\"\""));
	printf("\n");
	printf("test quore -1: ");
	printf("%d", test_quote("\'\'\'ho\'\"\'\'\'\'l\"a\'\'\'"));
	printf("\n");
	printf("test quore 1: ");
	printf("%d", test_quote("\'\"\"\"\'"));
	printf("\n");
	printf("test quore -1: ");
	printf("%d", test_quote("\"\'\'\'\"\""));
	printf("\n");
	printf("test quore -1: ");
	printf("%d", test_quote("lala\'\'\'lala"));
	printf("\n");
	printf("test quore 1: ");
	printf("%d", test_quote("lala\"sasa\'sas\"sasa"));
	printf("\n");
	return (0);
}
