/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:06:44 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/05 11:50:11 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (n <= ft_strlen(dst))
		return (n + ft_strlen(src));
	i = ft_strlen(dst);
	while (src[j] != '\0' && i + 1 < n)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[j]));
}

//(17)- Index for destination string.
//(18)- Index for source string.
//(20)- Start from the beginning of 'src'.
//(22)- If 'n' is less than or equal to the length of 'dst',
//      return 'n' plus the length of 'src'.
//(23)- Get the length of 'dst' to start
//      adding 'src' from the end.
//(24)- Loop until the end of 'src' or until there's
//      no more space in 'dst'.
//(26)- Add 'src' to 'dst'.
//(30)- Null-terminate 'dst'
//(31)- Return the total length of 'dst' after concatenation
//      plus the remaining length of 'src'

/*
#include <stdio.h>

int	main(void) {
	char dest[22] = "Hello, ";
	const char *src = "world!";

	size_t size = ft_strlcat(dest, src, sizeof(dest) - sizeof("Hello, "));

	printf("Original: %s\n", dest);
	printf("After ft_strlcat: %s (%zu)\n", dest, size);

	return (0);
}*/