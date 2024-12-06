/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:14:16 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/18 13:14:42 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	i = 0;
	while (i++ < n)
		*d++ = *s++;
	return (dest);
}

// (15) - ft_memcpy, copies n bytes from src to dest.
// (17) - Declare i for indexing through the bytes.
// (18-19) - Pointers for byte level access to dest and src.
// (21-22) - Cast dest and src to char pointers for byte level manipulation.
// (23) - Set i to 0 for the loop.
// (24) - Start loop to copy n bytes from src to dest.
// (25) - Copy each byte from src to dest and increment pointers.
// (26) - Return the original dest pointer.

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "Hello, World!";
	char	dest[50];

	ft_memcpy(dest, src, strlen(src) + 1);
	printf("Source: %s\n", src);
	printf("Destination after memcpy: %s\n", dest);
	return (0);
}
*/