/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:36:04 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/05 10:28:49 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (s[size])
		size++;
	new = malloc(sizeof(char) * (size + 1));
	if (!(new))
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

//(17-19)-'*new' Pointer for new string, 'i' loop counter,
//	'size' size of oryginal string.
//(23-24)- Get string length (+ null terminator).
//(25)- Allocate memory for the new string.
//(26-27)-Check if memory allocation failed.
//(33)-  Null-terminate the new string.
//(34)- Return the duplicated string.

/*
#include <stdio.h>

int	main(void)
{
	const char	*str = "Testing!";
	char		*dup;

	dup = ft_strdup(str);
	if (dup)
	{
		printf("Original: %s\n", str);
		printf("Duplicated: %s\n", dup);
		free(dup);
	}
	else
	{
		printf("Error: ft_strdup failed.\n");
	}
	return (0);
}
*/