/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:05:12 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/02 12:15:44 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	casted_c;

	casted_c = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == casted_c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == casted_c)
		return ((char *)(s + i));
	return (NULL);
}
