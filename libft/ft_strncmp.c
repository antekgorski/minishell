/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:00:41 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:21:25 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares two strings up to a specified number of characters.
 *
 * This function compares the first `n` characters of the strings pointed to 
 * by `s1` and `s2`. It returns an integer less than, equal to, or greater 
 * than zero if the first `n` characters of `s1` are found to be 
 * lexicographically less than, to match, or be greater than those of `s2`.
 *
 * @param s1 A pointer to the first string to be compared.
 * @param s2 A pointer to the second string to be compared.
 * @param n The maximum number of characters to compare.
 *
 * @return An integer less than, equal to, or greater than zero if the 
 *         first `n` characters of `s1` are found to be less than, 
 *         to match, or be greater than those of `s2`. If `n` is zero, 
 *         the function returns 0.
 *
 * @note If `s1` and `s2` are both NULL, the behavior is undefined.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
	{
		return (0);
	}
	while (*s1 && *s2 && (*s1 == *s2) && (n > 1))
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
