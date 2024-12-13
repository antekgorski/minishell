/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:20:15 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/02 12:16:11 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;

	dst_len = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	if (!size)
		return (dst_len + ft_strlen(src));
	i = 0;
	while (i + dst_len < size - 1 && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len < size)
		dst[dst_len + i] = 0;
	return (dst_len + ft_strlen(src));
}
