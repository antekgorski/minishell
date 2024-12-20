/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:41:26 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:59:04 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a character is in a specified set of characters.
 *
 * This function iterates over the string `set` to determine if the
 * character `c` is present within it.
 *
 * @param c The character to check.
 * @param set The string containing the set of characters.
 *
 * @return 1 if `c` is found in `set`, otherwise 0.
 */

static int	ft_set_in_s(const char *set, char c)
{
	if (ft_strchr(set, (int)c))
		return (1);
	else
		return (0);
}

/**
 * @attention MALOC
 * @brief Trims characters from the beginning and end of a string.
 *
 * This function removes all leading and trailing characters from
 * the string `s1` that are present in the string `set`.
 *
 * @param s1 The string to be trimmed.
 * @param set The set of characters to remove from the edges of `s1`.
 *
 * @return A newly allocated string that is the trimmed version of
 *         `s1`, or NULL if memory allocation fails or if either
 *         input is NULL.
 *
 * @note The resulting string will always be null-terminated.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimedstr;
	size_t	begin;
	size_t	fin;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	fin = 0;
	begin = 0;
	while (*(s1 + begin) && ft_set_in_s(set, *(s1 + begin)))
	{
		begin++;
	}
	fin = ft_strlen(s1);
	while ((fin > begin) && ft_set_in_s(set, *(s1 + (fin - 1))))
		fin--;
	trimedstr = (char *)malloc(sizeof(*s1) * (fin - begin + 1));
	if (trimedstr == NULL)
		return (NULL);
	i = 0;
	while (fin > begin)
		*(trimedstr + i++) = *(s1 + begin++);
	*(trimedstr + i) = '\0';
	return (trimedstr);
}
