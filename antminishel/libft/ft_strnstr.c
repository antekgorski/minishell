/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:56:49 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:21:30 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates a substring in a string, up to a specified length.
 *
 * The function locates the first occurrence of the null-terminated string
 * `little` in the string `big`, where not more than `len` characters are
 * searched. The function returns a pointer to the first character of the
 * located substring, or `NULL` if the substring is not found.
 *
 * @param big The string to be searched.
 * @param little The substring to search for.
 * @param len The maximum number of characters to search in `big`.
 *
 * @return A pointer to the first occurrence of `little` in `big`, or `NULL`
 *         if `little` is not found within the first `len` characters of `big`.
 *
 * @note If `little` is an empty string, the function returns `big`.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if ((big == NULL) && (len == 0))
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	while (*big && len)
	{
		while (*(little + i) == *(big + i) && (i < len) && *(little + i))
		{
			if (*(little + i + 1) == '\0')
				return ((char *)big);
			i++;
		}
		big++;
		len--;
	}
	return (NULL);
}
