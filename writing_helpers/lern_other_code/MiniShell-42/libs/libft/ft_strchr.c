/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:01:26 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/05 10:10:15 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

//(15)- Function take 'const char *s' that is our string,
//		and 'int c' that is our character we look for.
//(17-19)- If out character has not been found return NULL.
//(20)- If it has been found return location of this character.

/*
#include <stdio.h>

int	main(void) {
	const char *str = "Hello, world!";
	char c = 'w';

	char *result = ft_strchr(str, c);

	if (result) {
		printf("'%c' found at %p (offset %ld characters)\n", c, result, result
			- str);
	} else {
		printf("'%c' not found in the string\n", c);
	}

	return (0);
}
*/