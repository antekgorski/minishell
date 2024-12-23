/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:51:59 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:17:56 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Moves a block of memory from source to destination.
 *
 * The function copies `n` bytes from the memory area pointed to by `src` 
 * to the memory area pointed to by `dest`, handling potential overlap 
 * between the two memory areas. If the areas overlap, the copy is done 
 * in a manner that ensures the original data is preserved.
 *
 * @param dest A pointer to the destination memory area where the content 
 *             is to be moved.
 * @param src A pointer to the source memory area from which the content 
 *            is to be moved.
 * @param n The number of bytes to move from `src` to `dest`.
 * 
 * @return A pointer to the destination memory area `dest`.
 * 
 * @note If both `dest` and `src` are `NULL`, the function returns `NULL`. 
 *       The function handles overlapping regions correctly, ensuring data 
 *       integrity during the move operation.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_temp;
	const char	*src_temp;

	dest_temp = dest;
	src_temp = src;
	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	if (dest < src)
	{
		while (n--)
			*dest_temp++ = *src_temp++;
	}
	else
	{
		dest_temp = dest_temp + (n - 1);
		src_temp += (n - 1);
		while (n--)
			*dest_temp-- = *src_temp--;
	}
	return (dest);
}
