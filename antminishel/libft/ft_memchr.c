/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:28:07 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:17:47 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of a character in a memory block.
 *
 * The function scans the memory area pointed to by `s` for the first occurrence 
 * of the character `c`, examining up to `n` bytes. If the character is found, 
 * a pointer to the matching byte is returned. If the character is not found 
 * within the given range, the function returns `NULL`.
 *
 * @param s A pointer to the memory block to be searched.
 * @param c The character to search for, passed as an `int` but treated as 
 *          an `unsigned char`.
 * @param n The number of bytes to be examined in the memory block.
 * 
 * @return A pointer to the first occurrence of `c` in the memory block, or 
 *         `NULL` if the character is not found within the specified range.
 * 
 * @note The function does not modify the memory block; it only reads from it.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- != 0)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
