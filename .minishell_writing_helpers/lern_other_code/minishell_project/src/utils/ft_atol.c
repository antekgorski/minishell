/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 08:05:00 by sehosaf           #+#    #+#             */
/*   Updated: 2024/06/19 21:21:08 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long	ft_atol(const char *str)
{
	int		sign;
	long	output;
	long	prev_output;

	sign = 1;
	output = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		prev_output = output;
		output = output * 10 + (*str - '0');
		if (sign == 1 && output < prev_output)
			return (LONG_MAX);
		if (sign == -1 && output > prev_output)
			return (LONG_MIN);
		str++;
	}
	return (output * sign);
}
