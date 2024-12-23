/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:17:41 by agorski           #+#    #+#             */
/*   Updated: 2024/12/22 18:43:26 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of a character in a string.
 *
 * The function searches for the first occurrence of the character `c` 
 * in the string `s`. The search includes the null terminator. 
 * If the character is found, a pointer to its location in the string 
 * is returned; otherwise, NULL is returned.
 *
 * @param s A pointer to the null-terminated string to be searched. 
 *          This string should not be NULL.
 * @param c The character to be located in the string. It is passed as 
 *          an integer, but it is interpreted as a character.
 * 
 * @return A pointer to the first occurrence of the character `c` in the 
 *         string `s`, or NULL if the character is not found. If `c` is 
 *         the null terminator, a pointer to the null terminator in `s` 
 *         is returned.
 *
 * @note The function does not perform any error checking on the input 
 *       string. If `s` is NULL, the behavior is undefined.
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		else
			s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}
