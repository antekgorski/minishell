/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:32:03 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/07 13:28:17 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr <= 0)
	{
		nbr = -nbr;
		count++;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static char	*ft_pre_conv(int len)
{
	char	*tmp;

	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[len] = '\0';
	return (tmp);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		len;
	char	*res;
	int		i;

	nbr = n;
	len = int_len(nbr);
	res = ft_pre_conv(len);
	if (!res)
		return (NULL);
	if (nbr == 0)
		res[0] = '0';
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	i = len - 1;
	while (nbr > 0)
	{
		res[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str;

	str = ft_itoa(52);
	printf("%s\n", str);
	free(str);
	return (0);
}
*/

// PART 1 - 	int_len
//(17) Create 'int count' to keep track of an number of digits.
//(19) Set 'count' value to 0 as starting value.
//(20-24) If 'nbr' is negative change it to positie
//			and inceremnt 'count' by one.
//(25-29) While 'nbr' is not 0 devide it by 10,
//			reduce lenght by one digit and increment 'count'.
//(30) Return total count of digits in the oryginal number.

// PART 2 - ft_pre_conv
//(35)	Declar '*tmp' to store the adress of allocated memory.
//(37)	Allocate memory for the string and add 1 byte of memory for NULL.
//(38-39) Check if the allocation was succesfull if not return NULL.
//(40) Set last byte of allocated memory to NULL to protely terminate is.
//(41) Return pointer to allocated nulterminated memory.

// PART 3 - ft_itoa
//(46) Use a 'long' in case where 'n' is minimal int.
//(47) 'len' store the length of the resulting string.
//(48) Pointer to the resulting string.
//(49) Iterator for positioning in the string.
//(51) Change 'int' to 'long' to handle negative values.
//(52) Calculate the 'len' of the number as a string, including sign.
//(53) Allocate memory for the string including NULL.
//(54-55) Check if memory allocation was succesful.
//(56-57) Special case for zero, directly set the first char to '0'.
//(58-62) Handle negative numbers. Set the first character to the '-'.
//			Make number '+' for easier processing.
//(63) Start filling the string from the end.
//(64-68) Convert each digit of 'nbr' to a 'char'
//			and fill the string from the end.
//(69) Return the resulting string.