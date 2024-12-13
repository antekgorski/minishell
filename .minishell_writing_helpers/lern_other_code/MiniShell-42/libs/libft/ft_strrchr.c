/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:11:48 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/06 12:26:38 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (last);
}

//(17)- Pointer to the last occurrence of 'c'.
//(19)- Initialize 'last' with NULL.
//(20)- Loop through the string 's'.
//(23)- Update 'last' to the current location.
//(24)- Move to the next character.
//(26)- Check the null terminator in case 'c' is '\0'.
//(27)- Return the current location if it's a match.
//(28)- Return 'last', the last occurrence of 'c', or NULL if not found.

/*
#include <stdio.h>

int	main(void) {
	char *str1 = "Hello, world!";
	char *str2 = "Mississippi";
	char *str3 = "Empty";
	char ch1 = 'o';
	char ch2 = 's';
	char ch3 = 'm';

	printf("'%s' last occurrence of '%c': %s\n", str1, ch1, ft_strrchr(str1,
			ch1));
	printf("'%s' last occurrence of '%c': %s\n", str2, ch2, ft_strrchr(str2,
			ch2));
	printf("'%s' last occurrence of '%c': %s\n", str3, ch3, ft_strrchr(str3,
			ch3));
	return (0);
}
*/