/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:45:44 by agorski           #+#    #+#             */
/*   Updated: 2024/12/21 14:35:07 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Appends the source string to the destination string with size limit.
 *
 * The function appends the string `src` to the end of `dst`, ensuring that
 * the total length of the resulting string does not exceed `size`. It also
 * guarantees that `dst` is null-terminated. If `size` is less than or equal
 * to the length of `dst`, the function does not modify `dst` and returns
 * the sum of the lengths of `dst` and `src`.
 *
 * @param dst A pointer to the destination string to which `src` will be
 *				appended. This string must be large enough to hold the result
 *            if `size` is greater than its current length.
 * @param src A pointer to the source string that will be appended to `dst`.
 * @param size The size of the buffer allocated for `dst`. It determines the
 *             maximum number of characters to append from `src` and ensures
 *             the resulting string is null-terminated.
 *
 * @return The total length of the string that would have been created if
 *         enough space had been available, which is the initial length of
 *         `dst` plus the length of `src`. If `size` is less than or equal
 *         to the length of `dst`, the return value will be the length of `src`
 *         plus `size`.
 *
 * @note The caller must ensure that `dst` has enough space allocated to hold
 *       the resulting string, including the null terminator.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	if (!dst || !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (src_len + size);
	if (src_len < size - dst_len)
		ft_memcpy(dst + dst_len, src, src_len + 1);
	else
	{
		ft_memcpy(dst + dst_len, src, size - dst_len - 1);
		dst[size - 1] = '\0';
	}
	return (dst_len + src_len);
}
