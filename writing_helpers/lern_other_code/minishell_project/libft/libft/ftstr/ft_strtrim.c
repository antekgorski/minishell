/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:16:42 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/02 12:16:43 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == 0 || set[0] == 0)
		return (ft_strdup(s1));
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (s1[i] == 0)
		return ((char *)ft_calloc(1, 1));
	start = i;
	end = i;
	while (s1[++i])
		if (!ft_strchr(set, s1[i]))
			end = i;
	res = ft_substr(s1, start, end - start + 1);
	return (res);
}
