/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:11:53 by agorski           #+#    #+#             */
/*   Updated: 2024/12/22 09:56:18 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_set_str(int len)
{
	char	*temp;

	temp = ft_calloc((len + 1) * sizeof(char), 1);
	if (temp == NULL)
		return (NULL);
	temp[len] = '\0';
	return (temp);
}

/**
 * @brief Counts the number of digits in an integer.
 *
 * This function calculates the number of digits in the given integer `n`.
 * If the integer is negative, it also counts the negative sign.
 *
 * @param n The integer whose digits are to be counted.
 *
 * @return The number of digits in `n`,
 *	including the negative sign if applicable.
 */
static int	ft_intlen(long len)
{
	int	count;

	count = 0;
	if (len < 0)
	{
		count++;
		len = -len;
	}
	if (len == 0)
		count++;
	if (len > 0)
	{
		while (len)
		{
			len /= 10;
			count++;
		}
	}
	return (count);
}

/**
* @attention MALLOC 
* @brief Converts an integer to a string.
* 
* @param n The integer to be converted.
*
* @return The string representation of the integer.
*/
char	*ft_itoa(int n)
{
	long	temp;
	int		i;
	char	*itoa;
	long	long_n;

	long_n = n;
	i = ft_intlen(long_n);
	itoa = ft_set_str(i);
	if (itoa == NULL)
		return (NULL);
	if (long_n == 0)
		itoa[0] = '0';
	if (n < 0)
	{
		itoa[0] = '-';
		long_n = -long_n;
	}
	while (long_n > 0)
	{
		temp = long_n % 10;
		long_n /= 10;
		itoa[i - 1] = temp + 48;
		i--;
	}
	return (itoa);
}
