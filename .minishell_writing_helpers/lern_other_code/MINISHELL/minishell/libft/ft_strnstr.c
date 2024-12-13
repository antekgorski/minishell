/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:21:01 by fursini           #+#    #+#             */
/*   Updated: 2023/01/26 08:56:34 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s && len == 0)
		return (NULL);
	if (!find[0] || !find)
		return ((char *)s);
	while (s[i] && i < len)
	{
		j = 0;
		while (s[i + j] == find[j] && i + j < len)
		{
			if (!find[j + 1])
				return ((char *)s + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
