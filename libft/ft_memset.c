/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:41:14 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:17:59 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Sets a block of memory to a specified value.
 *
 * The function fills the first `n` bytes of the memory area pointed to by 
 * `s` with the constant byte value `c`. This is commonly used to initialize 
 * memory or to clear a memory block.
 *
 * @param s A pointer to the memory area to be set.
 * @param c The value to set, which is converted to an unsigned char.
 * @param n The number of bytes to set to the specified value.
 * 
 * @return A pointer to the memory area `s`.
 * 
 * @note The function does not check for overlapping memory areas, as it is 
 *       intended to write to the specified memory area directly.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	void	*temp_s;

	temp_s = s;
	while (n--)
	{
		*((unsigned char *)temp_s++) = (unsigned char)c;
	}
	return (s);
}
