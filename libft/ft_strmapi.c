/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 23:58:14 by agorski           #+#    #+#             */
/*   Updated: 2024/12/22 02:50:03 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @attention MALLOC
 * @brief Applies a function to each character of a string,
 *	creating a new string.
 *
 * This function takes a string `s` and a function pointer `f`, applies `f`
 * to each character of `s`, and creates a new string with the results. The
 * function `f` takes an index and a character as parameters and returns a
 * new character.
 *
 * @param s A pointer to the null-terminated string to be processed.
 * @param f A pointer to the function that will be applied to each character
 *          of `s`. It takes an unsigned integer (the index of the character)
 *          and a character, and returns a character.
 *
 * @return A pointer to the newly created string with the transformed
 * characters, or NULL if memory allocation fails or if `s` is NULL.
 *
 * @note The returned string must be freed by the caller to avoid memory leaks.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	str = ft_calloc((ft_strlen(s) + 1) * sizeof(char), sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
