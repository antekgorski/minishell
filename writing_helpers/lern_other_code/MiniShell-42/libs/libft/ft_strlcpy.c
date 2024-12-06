/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:27:57 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/18 13:16:26 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	srcsize;
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (0);
	srcsize = ft_strlen(src);
	if (n != 0)
	{
		while (src[i] != '\0' && i < (n - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (srcsize);
}

//(17)- Size of the source string
//(18)- Iterator for copying characters
//(22)- Return 0 if either 'dest' or 'src' is NULL
//(23)- Calculate the length of 'src'
//(24)- Check if there is space in 'dest'
//      to copy at least the null terminator
//(26)- Copy src to dest until src ends or dest is full,
//      leaving room for '\0'.
//(31)- Ensure dest ends with '\0'.
//(33)- Return length of src.

/*
#include <stdio.h>

int	main(void)
{
	char		dest[20];
	const char	*src = "Test string";
	size_t		size1;

	size1 = ft_strlcpy(dest, src, sizeof(dest));
	printf("Copied: %s (original size %zu)\n", dest, size1);
	return (0);
}
*/