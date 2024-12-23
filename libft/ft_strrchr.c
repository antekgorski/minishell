/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:55:54 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:21:33 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the last occurrence of a character in a string.
 *
 * This function scans the string `s` for the last occurrence of the
 * character `c`. The search is performed from the end of the string
 * towards the beginning.
 *
 * @param s The string to be searched.
 * @param c The character to locate in the string.
 *
 * @return A pointer to the last occurrence of `c` in `s`, or NULL if
 *         the character is not found.
 *
 * @note If `c` is the null character ('\0'), the function returns a
 *       pointer to the null terminator of the string.
 */
char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurrence;

	last_occurrence = s;
	while (*s++ != '\0')
	{
		if (*s == (char)c)
			last_occurrence = s;
	}
	if (*last_occurrence != (char)c && (char)c != '\0')
		return (NULL);
	return ((char *)last_occurrence);
}
