/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:50:59 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/18 13:14:39 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_str;
	unsigned char	*s2_str;

	s1_str = (unsigned char *)s1;
	s2_str = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_str[i] != s2_str[i])
		{
			return (s1_str[i] - s2_str[i]);
		}
		i++;
	}
	return (0);
}

// (15) - Function parameters: two memory areas
// 			(s1,s2) and number of bytes to compare (n).
// (17) - Declare i for indexing through the memory areas.
// (18-19) - Pointers for byte-wise access to s1 and s2.
// (21-22) - Cast s1 and s2 to unsigned char pointers for comparison.
// (23) - Set i to 0 as start value.
// (24) - Start loop to compare n bytes of s1 and s2.
// (26-29) - If bytes differ, return the difference between them.
// (30) - Increment i to move to the next byte.
// (32) - Return 0 if all compared bytes are the same.

/*
#include <stdio.h>

int	main(void) {
	char str1[] = "Hello";
	char str2[] = "Hello, world!";
	char str3[] = "Hello";
	size_t n = sizeof(str1) - 1; // Exclude null terminator

	int result1 = ft_memcmp(str1, str2, n);
	int result2 = ft_memcmp(str1, str3, n);

	printf("ft_memcmp(str1, str2, %zu): %d\n", n, result1);
	printf("ft_memcmp(str1, str3, %zu): %d\n", n, result2);

	return (0);
}
*/