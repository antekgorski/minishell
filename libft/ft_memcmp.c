/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:05:30 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:17:50 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares two memory blocks.
 *
 * The function compares the first `n` bytes of the memory blocks pointed to 
 * by `s1` and `s2`. It returns an integer less than, equal to, or greater than 
 * zero if the first byte that does not match is less than, equal to, or greater 
 * than the corresponding byte in the other memory block. If the two memory 
 * blocks are equal up to `n` bytes, the function returns 0.
 *
 * @param s1 A pointer to the first memory block to be compared.
 * @param s2 A pointer to the second memory block to be compared.
 * @param n The number of bytes to be compared.
 * 
 * @return An integer less than, equal to, or greater than zero if the first 
 *         `n` bytes of `s1` are found, respectively, to be less than, to match, 
 *         or be greater than the first `n` bytes of `s2`.
 * 
 * @note The function treats the memory areas as arrays of unsigned char, 
 *       ensuring that the comparison is performed in a byte-wise manner.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*exts1;
	const unsigned char	*exts2;

	exts1 = (const unsigned char *)s1;
	exts2 = (const unsigned char *)s2;
	while (n != 0)
	{
		if (*exts1 != *exts2)
		{
			return (*exts1 - *exts2);
		}
		exts1++;
		exts2++;
		n--;
	}
	return (0);
}
