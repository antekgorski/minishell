/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:32:33 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:21:04 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies a function to each character of a string, 
 *        passing its index and value.
 *
 * The function iterates over each character in the string `s`, 
 * applying the function `f` to each character. The index of the 
 * character in the string is passed as the first argument to `f`, 
 * and a pointer to the character itself is passed as the second 
 * argument.
 *
 * @param s A pointer to the null-terminated string to iterate over. 
 *          This string must not be NULL.
 * @param f A pointer to a function that takes an unsigned int (the 
 *          index) and a pointer to a character. This function is 
 *          applied to each character in the string.
 *
 * @note The function does not return a value and modifies the 
 *       characters in place if the provided function modifies them.
 *       Ensure that `f` is not NULL before calling this function to 
 *       avoid dereferencing a NULL pointer.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return ;
	while (i < ft_strlen(s))
	{
		(*f)(i, &s[i]);
		i++;
	}
}
