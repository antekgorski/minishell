/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:21:22 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/18 13:16:59 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	new_str = (char *)malloc(len + 1);
	if (!s || !(new_str))
		return (NULL);
	while (i < ft_strlen(s) && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}

//(17)- Pointer for the new substring.
//(18)- Iterator for the original string 's', starts from 'start'.
//(19)- Iterator for the new string 'new_str'.
//(21)- Initialize 'i' with the start position in 's'
//(22)- Start filling 'new_str' from the beginning
//(23)- Allocate memory for the new string, including space for null terminator.
//(24)- Check if 's' is NULL or memory allocation failed
//(25)- Return NULL in case of error
//(26)- Copy up to 'len' characters from 's' starting at 'start' to 'new_str'
//(27)- Copy character and increment both indexes
//(28)- Null-terminate the new string
//(29)-Return the newly created substring

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void) {
  char *source_string = "Hello, world!";
  unsigned int start = 7;
  size_t length = 5;

  char *substring = ft_substr(source_string, start, length);

  if (substring) {
	printf("Extracted substring: %s\n", substring);
	free(substring);
  } else {
	printf("Error: Substring extraction failed.\n");
  }

  return (0);
}
*/