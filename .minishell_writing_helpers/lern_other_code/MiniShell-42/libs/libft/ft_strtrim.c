/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:00:48 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/06 19:30:26 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	end = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}

// PART-1
//(17)- Index for looping through the set.
//(19)- Initialize index to start from the beginning of the set.
//(20)- Loop through each character in the set until the end.
//(22)- Check if the current character in the set matches 'c'.
//(23)- Return 1 (true) if a match is found.
//(24)- Increment the index to move to the next character in the set.
//(26)- Return 0 (false) if no match is found by the end of the set.

// PART-2
//(31)- Pointer to the trimmed string.
//(32)- Iterator for copying characters to 'str'.
//(33)- Index to mark the start of non-set characters in 's1'.
//(34)- Index to mark the end of non-set characters in 's1'.
//(36)- Initialize 'end' with the length of 's1'.
//(37)- Initialize 'start' at the beginning of 's1'.
//(38-39)- Increment 'start' past leading set chars.
//(40-41)- Decrement 'end' to exclude trailing set chars.
//(42)- Allocate memory for the trimmed string.
//(43)- Check if memory allocation failed.
//(44)- Return NULL if allocation failed.
//(45)- Initialize iterator for copying characters.
//(46)- Copy characters from 'start' to 'end' from 's1' to 'str'.
//(47)- Increment both 'start' and 'i' during copy.
//(48)- Null-terminate the new string.
//(49)- Return the trimmed string.

/*
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	printf("%s", ft_strtrim("** hello w*rld*", "*"));
	return (0);
}
*/