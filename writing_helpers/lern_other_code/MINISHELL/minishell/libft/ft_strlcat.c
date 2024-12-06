/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:59:06 by fursini           #+#    #+#             */
/*   Updated: 2023/01/26 08:58:15 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;
	size_t	j;

	if (!dst && size == 0)
		return (0);
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = 0;
	j = d_len;
	if (d_len >= size)
		return (size + s_len);
	if (size > 0)
	{
		while (src[i] && d_len + i < size - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	return (d_len + s_len);
}

// int main()
// {
// 	char	*str;
// 	int s2 = ft_strlcat(str, "aoao", 0);
// 	printf("%s\n%d\n", str, s2);
// }
