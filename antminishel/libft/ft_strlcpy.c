/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:10:02 by agorski           #+#    #+#             */
/*   Updated: 2024/12/21 23:34:31 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies the string from the source to the destination with size limit.
 *
 * The function copies up to `size - 1` characters from the string `src` to
 * `dst`, ensuring that `dst` is null-terminated. If `size` is less than or
 * equal to 0, the function will not copy any characters and will return
 * the length of `src`.
 *
 * @param dst A pointer to the destination string where `src` will be copied.
 *            It must be large enough to hold the resulting string and the
 *            null terminator.
 * @param src A pointer to the source string that will be copied to `dst`.
 * @param size The size of the buffer allocated for `dst`, which limits the
 *             number of characters to copy from `src`.
 *
 * @return The total length of the string that would have been copied, which
 *         is the length of `src`. If `size` is less than or equal to 0,
 *         it will return the length of `src` without copying any characters.
 *
 * @note If `dst` is NULL or `src` is NULL, the function returns 0 without
 *       performing any operations.
 */
size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	int	i;

	if (!dest || !src)
		return (0);
	i = 0;
	if (size == 0)
	{
		while (*(src + i))
			i++;
		return (i);
	}
	while (*(src + i) && --size)
	{
		*dest++ = *(src + i++);
	}
	*dest = '\0';
	while (*(src + i))
	{
		++i;
	}
	return (i);
}
