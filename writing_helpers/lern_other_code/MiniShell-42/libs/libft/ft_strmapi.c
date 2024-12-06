/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:06:24 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/06 14:17:42 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = 0;
	res = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < ft_strlen(s))
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// PART1
//(15)- Define function ft_strmapi with string 's' and
//    function pointer 'f' as parameters.
//(17-18)- Declare iterator 'i' and pointer 'res' for result string.
//(20)- Initialize iterator 'i' to 0.
//(21)- Allocate memory for 'res' based on the length of 's'
//    plus one for the null terminator.
//(22-23)- Check if memory allocation for 'res' failed and return NULL if so.
//(26)- Iterate over 's', apply 'f' to each character, and assign to 'res'.
//(29)- Null-terminate the result string 'res'.
//(30)- Return the modified string 'res'.

/*
#include <stdio.h>

inc_char(unsigned int i, char c)
{
	(void)i;
	return (c + 1);
}

int	main(void) {char
	char const *str = "abcdef";
	char *mod_str;

	mod_str = ft_strmapi(str, inc_char);
	if (mod_str != NULL) {
		printf("Original string: %s\n", str);
		printf("Modified string: %s\n", mod_str);
		free(mod_str);
	} else {
		printf("Memory allocation failed.\n");
	}

	return (0);
}*/
