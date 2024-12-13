/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:02:05 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/04 19:26:54 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	char	*p;

	p = (char *)s;
	while (len > 0)
	{
		p[len - 1] = c;
		len--;
	}
	return (s);
}

// (15) Begin setting memory area.
// (17) Use p to go through the memory.
// (19) Make s easy to work with by treating it as a series of bytes.
// (20) Start filling the memory with the byte c.
// (22-23) Work from the end, replacing each byte with c, until all are set.
// (25) Return the memory area after filling it.

/*
#include <stdio.h>

int	main(void)
{
	char	str[50] = "Hello, world! This is a test string.";
	int		c;
	size_t	len;

	c = 'X';
	len = 10;
	printf("Before ft_memset: %s\n", str);
	ft_memset(str, c, len);
	printf("After ft_memset: %s\n", str);
	return (0);
}
*/
