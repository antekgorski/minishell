/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:54:07 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/18 13:50:41 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubchr(const char *s, char c)
{
	char	*ptr;

	ptr = ft_strchrs(s, c);
	if (!ptr)
		return (NULL);
	return (ft_substr(s, 0, ptr - s));
}
