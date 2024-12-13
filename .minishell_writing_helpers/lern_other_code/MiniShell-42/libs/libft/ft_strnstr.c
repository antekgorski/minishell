/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:00:19 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/06 11:54:32 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*big_str;
	size_t	left;
	size_t	lit_len;
	size_t	i;

	i = 0;
	big_str = (char *)big;
	if (little[0] == '\0')
		return (big_str);
	left = len;
	lit_len = (size_t)ft_strlen(little);
	while (*big_str && left >= lit_len)
	{
		if (*big_str == *little)
		{
			if (ft_strncmp(little, big_str, lit_len) == 0)
				return (big_str);
		}
		i++;
		left--;
		big_str++;
	}
	return (NULL);
}

//(17)- Pointer to navigate through 'big'.
//(18)- Remaining length to search within 'big'.
//(19)- Length of 'little'.
//(20)- Loop counter.
//(23)- Initialize big_str with big's address for navigation.
//(24-25)- If 'little' is an empty string, return 'big'.
//(26)- Initialize 'left' with the total length allowed to search.
//(27)- Calculate length of 'little'.
//(28)- Loop until end of 'big' or insufficient 'left'.
//(30)- Check if current character matches the start of 'little'
//(32)- Compare substring of 'big' with 'little'.
//(33)- Return current position if they match.
//(35)- Increment loop counter.
//(36)- Decrement remaining length.
//(37)- Move to the next character in 'big'.
//(39)- Return NULL if 'little' is not found in 'big' within 'len' characters.

/*
#include <stdio.h>

int	main(void)
{
	const char	*big = "This is a string with a needle in a haystack";
	const char	*little = "needle";
	size_t		len;

	len = 20;
	printf("ft_strnstr: %s\n", ft_strnstr(big, little,
			len) ?: "No match within limit");
	return (0);
}
*/