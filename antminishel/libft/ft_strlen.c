/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:30:39 by agorski           #+#    #+#             */
/*   Updated: 2024/12/21 23:53:06 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculates the length of a string.
 *
 * This function computes the length of the string `s`, not including the
 * null terminator. If the input string is NULL, the function returns 0.
 *
 * @param s A pointer to the null-terminated string whose length is to be
 *          computed.
 *
 * @return The length of the string `s`, or 0 if `s` is NULL.
 *
 * @note This function does not count the null terminator in the returned
 *       length.
 */
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (*str == '\0')
		return (0);
	while (*(str + i))
		i++;
	return (i);
}
