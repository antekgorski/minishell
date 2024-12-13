/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:12:21 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/02 12:16:34 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	const char		*res;
	unsigned char	casted_c;

	casted_c = (unsigned char)c;
	res = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == casted_c)
			res = s + i;
		i++;
	}
	if (s[i] == casted_c)
		res = s + i;
	return ((char *)res);
}
