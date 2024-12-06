/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:39:41 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/02 12:16:29 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t	i;
	size_t	j;

	if (!sub[0])
		return ((char *)str);
	i = 0;
	j = 0;
	while (str[i] && i < len)
	{
		if (str[i] != sub[j])
			j = 0;
		if (str[i] == sub[j])
		{
			j++;
			if (!sub[j])
				return ((char *)(str + i - j + 1));
		}
		i++;
	}
	return (NULL);
}
