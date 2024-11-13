/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:21:14 by agorski           #+#    #+#             */
/*   Updated: 2024/11/07 13:17:24 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_len(unsigned int number)
{
	int	len;

	len = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

static void	write_function(char c)
{
	write(1, &c, 1);
}

static void	ft_putunsigned(unsigned int n)
{
	if (n >= 10)
	{
		ft_putunsigned(n / 10);
		ft_putunsigned(n % 10);
	}
	else
		write_function(n + '0');
}

int	print_unsigned(unsigned int number)
{
	ft_putunsigned(number);
	return (ft_number_len(number));
}
