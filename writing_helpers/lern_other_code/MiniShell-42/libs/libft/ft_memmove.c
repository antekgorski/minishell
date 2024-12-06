/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:01:17 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/18 13:14:50 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	if (d > s)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	else if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

// (15) Start the function to move memory.
// (17) Use i to count through the bytes.
// (18-19) Use d and s as pointers to the destination and source memory.
// (21) Set i to 0 to start from the beginning.
// (22-23) Treat the memory addresses as arrays
//			 of characters for easy byte access.
// (24) Check if we need to copy backwards to
//		avoid overwrite when destination is after source.
// (26-30) Copy bytes one by one from the end
//			 if destination overlaps and is after source.
// (32) Check if we need to copy forwards
//			(normal case when destination is before source).
// (34-38) Copy bytes one by one from the start
//			if no overlap or destination is before source.
// (40) Return the original destination address after moving the memory.

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
  int source[10] = {1,2,3,4,5,6,7,8,9,10};
  int destination[10];
  ft_memmove(destination, source, sizeof(int) * 10);
  for (int i = 0; i < 10; i++)
	printf("destination[%d]=%d\n", i, destination[i]);
  for (int i = 0; i < 10; i++)
	printf("source[%d]=%d\n", i, source[i]);

  return (0);
}*/