/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:20:09 by agorski           #+#    #+#             */
/*   Updated: 2025/01/29 23:22:53 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 	comparing two strings
 * @param s1 first string
 * @param s2 second string
 * @return 0 if strings are equal, 1 if not
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
	{
		if (!s1 && !s2)
			return (0);
		if (!s1)
			return (-1);
		return (1);
	}
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
