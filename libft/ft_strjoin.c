/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:39:53 by agorski           #+#    #+#             */
/*   Updated: 2024/12/23 14:40:42 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *
 * @brief <<MALLOC>> Joins two strings into a new dynamically allocated string.
 * @brief The function concatenates the strings pointed to by `s1` and `s2`,
 * @brief allocating sufficient memory for the resulting string, including
 * @brief the null terminator. If either `s1` or `s2` is NULL, the function
 * @brief handles these cases by returning a duplicate of the non-NULL string
 * @brief or NULL if both are NULL.
 *
 * @param s1 A pointer to the first null-terminated string to be joined.
 *            If NULL, `s2` will be returned as a duplicate.
 * @param s2 A pointer to the second null-terminated string to be joined.
 *            If NULL, `s1` will be returned as a duplicate.
 *
 * @return A pointer to the newly allocated string that contains the
 *         concatenated result of `s1` and `s2`, or NULL if memory
 *         allocation fails or both `s1` and `s2` are NULL.
 * 			if one of is NULL returning a duplicate of the non-NULL string
 *
 * @note The caller is responsible for freeing the memory allocated for
 *       the resulting string to avoid memory leaks.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*costr;

	costr = NULL;
	if (!s1 && !s2)
		return (NULL);
	costr = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (costr == NULL)
		return (NULL);
	ft_strlcpy(costr, (char *)s1, (ft_strlen(s1) + 1));
	ft_strlcat(costr, (char *)s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (costr);
}
