/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:22:49 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/06 10:25:45 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && *(unsigned char *)s1 == *(unsigned char *)s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

//(17)- while elements in while are more than 0 we will continue a loop.
//(19-20)-	we iterate our index 's1' 's2'  to chekc another caracter.
//(21)-	we decrent amount of spots left to check
//(23-24)- if n will be 0 than return 0.
//(25)-	retur value of diference between characters in ASCII.

/*
#include <stdio.h>

int	main(void)
{
	char	c[] = "zdanie";
	char	b[] = "zdnie";

	printf("%d", ft_strncmp(c, b, 1));
}
*/