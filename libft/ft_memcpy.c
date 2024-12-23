/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:50:12 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:17:53 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies a block of memory from source to destination.
 *
 * The function copies `n` bytes from the memory area pointed to by `src` 
 * to the memory area pointed to by `dest`. The memory areas must not overlap; 
 * behavior is undefined if they do.
 *
 * @param dest A pointer to the destination memory area where the content 
 *             is to be copied.
 * @param src A pointer to the source memory area from which the content 
 *            is to be copied.
 * @param n The number of bytes to copy from `src` to `dest`.
 * 
 * @return A pointer to the destination memory area `dest`.
 * 
 * @note The function does not check for overlapping memory areas. If 
 *       the source and destination overlap, the behavior is undefined.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_temp;
	const char	*src_temp;

	dest_temp = dest;
	src_temp = src;
	if (!dest && !src)
		return (dest);
	while (n--)
	{
		*dest_temp++ = *src_temp++;
	}
	return (dest);
}
