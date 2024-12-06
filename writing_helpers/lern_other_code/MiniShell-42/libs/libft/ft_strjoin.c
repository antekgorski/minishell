/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:03:49 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/05 11:11:07 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	total_len;
	char	*str;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	total_len = len1 + len2 + 1;
	str = malloc(total_len);
	if (!str)
	{
		return (NULL);
	}
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2);
	str[total_len - 1] = '\0';
	return (str);
}

//(18)- Length of the first string.
//(19)- Length of the second string.
//(20)- Total length of the new string.
//(21)- Pointer for the joined string.
//(23)- Check if either input string is NULL.
//(27)- Get the length of the first string.
//(28)- Get the length of the second string.
//(29)- Calculate total length needed for the new string.
//(30)- Allocate memory for the new string.
//(31)- Check if memory allocation failed.
//(35)- Copy the first string into the new string.
//(36)- Copy the second string into the new string right after the first one.
//(37)- Null-terminate the new string.
//(38)- Return the joined string.

/*
#include <stdio.h>

int	main(void) {
	char *s1 = "Hello, ";
	char *s2 = "world!";
	char *joined = ft_strjoin(s1, s2);

	if (joined) {
		printf("Joined string: %s\n", joined);
		free(joined);
	} else {
		printf("ft_strjoin failed: Could not allocate memory.\n");
	}

	return (0);
}*/