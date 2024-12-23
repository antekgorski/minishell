/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:04:22 by agorski           #+#    #+#             */
/*   Updated: 2024/12/22 02:50:41 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @attention MALOC
 * @brief Creates a substring from a given string.
 *
 * This function allocates memory for a new string that contains
 * a portion of the original string `s`, starting from the index
 * `start` and extending for up to `len` characters.
 *
 * @param s The original string from which to create the substring.
 * @param start The starting index from which to extract the substring.
 * @param len The maximum length of the substring to be extracted.
 *
 * @return A newly allocated substring, or NULL if memory allocation
 *         fails. If `start` is greater than the length of `s`,
 *         an empty string is returned. If `len` exceeds the length
 *         of the substring from `start`, it is adjusted accordingly.
 *
 * @note The resulting substring will always be null-terminated.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = (char *)ft_calloc(len + 1, sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, (char *)s + start, len + 1);
	return (substr);
}
