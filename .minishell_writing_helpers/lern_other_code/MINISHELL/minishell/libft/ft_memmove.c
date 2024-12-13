/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:31:48 by fursini           #+#    #+#             */
/*   Updated: 2023/01/26 05:06:50 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	int	i;

	if (!s1 && !s2)
		return (NULL);
	if (s1 > s2)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			((char *)s1)[i] = ((char *)s2)[i];
			i--;
		}
		return ((void *)s1);
	}
	i = 0;
	while (i < (int)n)
	{
		((char *)s1)[i] = ((char *)s2)[i];
		i++;
	}
	return ((void *)s1);
}
