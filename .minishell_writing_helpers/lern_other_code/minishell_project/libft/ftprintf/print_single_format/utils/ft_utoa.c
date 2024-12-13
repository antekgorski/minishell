/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:03:59 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/20 18:06:40 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_single_format.h"

static int	utoa_res_len(unsigned int n)
{
	int	res;

	res = 1;
	while (n > 9)
	{
		res++;
		n /= 10;
	}
	return (res);
}

char	*ft_utoa(unsigned int n)
{
	char	*res;
	int		res_len;
	int		i;

	res_len = utoa_res_len(n);
	res = (char *)malloc((res_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[res_len] = 0;
	i = res_len - 1;
	while (n > 0 || i == res_len - 1)
	{
		res[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
