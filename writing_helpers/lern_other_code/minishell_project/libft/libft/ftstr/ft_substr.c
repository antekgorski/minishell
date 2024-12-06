/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:16:49 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/02 12:16:50 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	while (s[i] && i <= start)
		i++;
	if (i <= start)
		return (ft_calloc(1, sizeof(char)));
	i--;
	while (s[i] && i < start + len)
		i++;
	res = (char *)malloc(i - start + 1 * sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, s + start, i - start);
	res[i - start] = 0;
	return (res);
}
