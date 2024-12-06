/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:24:56 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/04 16:56:14 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	sign = 1;
	n = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sign);
}

// (17)String iterator.
// (18)For sign of number '+','-'.
// (19)Value to return.
// (21)Start value for 'i'.
// (22)Assume the number is '+' unless '-' founded.
// (23)Starting value for 'n'.
// (24-25)Skip white spaces.
// (26-30)Check is value in begining '-'.
// (28)If yes set sign as negative.
// (31-33)Check if there is a '+'.
// (33-37)Convert str to int.
// (38)Return the number with its correct sign.

/*
#include <stdio.h>

int	main(void)
{
	printf("%i", ft_atoi("r"));
	return (0);
}
*/
