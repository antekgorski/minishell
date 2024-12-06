/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:52:15 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/07 09:53:37 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// PART -1
//(17)-	Iterator for the loop.
//(20)- Loop through each character of the string
//      until the null terminator.
//(22)-	Call the function 'f' with the current index
//		and a pointer to the current character.
//(23)- Move to the next character.

/*
#include <ctype.h>
#include <stdio.h>

void	capitalize_even_index(unsigned int i, char *c)
{
	if (i % 2 == 0)
	{
		*c = ft_toupper(*c);
	}
}

int	main(void)
{
	char str[] = "abcd";

	printf("Before: %s\n", str);
	ft_striteri(str, capitalize_even_index);
	printf("After: %s\n", str);

	return (0);
}*/