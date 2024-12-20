/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:16:02 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:13:00 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Sets a block of memory to zero.
 *
 * The function writes `n` zero bytes to the memory area pointed to by `s`.
 * It is often used to clear or reset memory buffers.
 *
 * @param s A pointer to the memory area to be zeroed.
 * @param n The number of bytes to set to zero.
 * 
 * @return None.
 * 
 * @note This function is typically used to initialize or reset buffers by 
 *       filling them with zero bytes (`'\0'`). It behaves similarly to 
 *       the standard `bzero` function.
 * 
 * @warning The behavior is undefined if `s` is `NULL` or if `n` is greater 
 *          than the size of the allocated memory for `s`.
 */
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*del;

	del = (unsigned char *)s;
	while (n--)
	{
		*del = '\0';
		del++;
	}
}
