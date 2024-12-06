/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:10:06 by fursini           #+#    #+#             */
/*   Updated: 2023/01/26 00:27:17 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s2;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	s2 = ft_strdup(s);
	if (!s2)
		return (NULL);
	while (s[i])
	{
		s2[i] = f(i, *(char *)(s + i));
		i++;
	}
	return (s2);
}
