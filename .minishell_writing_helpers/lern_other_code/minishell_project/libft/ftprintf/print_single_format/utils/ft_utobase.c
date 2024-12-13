/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utobase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:03:49 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/17 18:14:17 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_single_format.h"

static uintptr_t	get_max_base(uintptr_t n, size_t base_len, size_t *res_len)
{
	uintptr_t	max_base;

	max_base = 1;
	*res_len = 2;
	while (n / max_base >= base_len)
	{
		max_base *= base_len;
		(*res_len)++;
	}
	return (max_base);
}

char	*ft_utobase(uintptr_t n, const char *base)
{
	size_t		base_len;
	uintptr_t	max_base;
	size_t		res_len;
	size_t		i;
	char		*res;

	base_len = ft_strlen(base);
	max_base = get_max_base(n, base_len, &res_len);
	res = (char *)malloc(res_len * sizeof(char));
	if (!res)
		return (NULL);
	res[res_len - 1] = 0;
	i = 0;
	while (max_base != 0)
	{
		res[i++] = base[n / max_base];
		n -= max_base * (n / max_base);
		max_base /= base_len;
	}
	return (res);
}
