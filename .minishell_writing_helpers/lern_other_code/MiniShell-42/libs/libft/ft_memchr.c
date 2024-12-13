/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:30:23 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/18 13:17:24 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	chr;

	str = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*str == chr)
		{
			return (str);
		}
		str++;
		i++;
	}
	return (NULL);
}

// (15) Setup function with parameters: memory (s),
//			character to find (c), number of bytes to check (n).
// (17) Counter for loop.
// (18) Pointer to go through memory.
// (19) The character we're looking for, as a byte.
// (21) Make s into a byte pointer to work with it.
// (22) Convert c into a byte to compare.
// (23) Start 'i' at 0.
// (24) Loop through memory.
// (26-29) If we find the character, return where it was found.
// (30) Move to the next index.
// (31) Increase 'i'.
// (33) If character not found, return NULL.

/*
#include <stdio.h>

int	main(void) {
	char str[] = "Hello, world!";
	char c = 'o';
	size_t n = sizeof(str) - 1;

	char *result = ft_memchr(str, c, n);

	if (result) {
		printf("First occurrence of '%c' found at: %s\n", c, result);
	} else {
		printf("Character '%c' not found within %zu bytes.\n", c, n);
	}

	return (0);
}
*/