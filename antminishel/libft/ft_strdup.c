/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:22:14 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:21:01 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Duplicates a string by allocating memory for a new copy.
 *
 * The function allocates sufficient memory to hold a copy of the 
 * string pointed to by `s`, and then copies the content of `s` 
 * into the newly allocated memory, including the null terminator. 
 * If memory allocation fails, the function returns NULL.
 *
 * @param s A pointer to the null-terminated string to be duplicated. 
 *          This string must not be NULL.
 * 
 * @return A pointer to the newly allocated string that is a duplicate 
 *         of `s`, or NULL if memory allocation fails.
 *
 * @note The caller is responsible for freeing the memory allocated 
 *       for the duplicated string to avoid memory leaks.
 */
char	*ft_strdup(const char *s)
{
	char	*new;

	new = malloc(ft_strlen(s) + 1);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, (char *)s, ft_strlen(s) + 1);
	return (new);
}
