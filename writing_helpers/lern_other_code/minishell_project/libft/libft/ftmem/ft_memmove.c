/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:55:34 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/02 12:14:42 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		dir;
	size_t	i;

	if (len == 0 || dst == src)
		return (dst);
	dir = 1;
	i = 0;
	if (dst > src)
	{
		dir = -1;
		i = len - 1;
	}
	while (i < len)
	{
		((char *)dst)[i] = ((char *)src)[i];
		if (i == 0 && dir == -1)
			break ;
		i += dir;
	}
	return (dst);
}
