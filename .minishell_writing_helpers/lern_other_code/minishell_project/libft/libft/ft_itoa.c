/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:13:17 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/02 12:13:18 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	itoa_res_len(int n)
{
	int	res;

	res = 1;
	if (n < 0)
		res++;
	while (n < -9 || n > 9)
	{
		res++;
		n /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		res_len;
	int		i;
	int		abs_multiplayer;

	res_len = itoa_res_len(n);
	res = (char *)malloc((res_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[res_len] = 0;
	i = res_len - 1;
	abs_multiplayer = -2 * (n < 0) + 1;
	while (n * abs_multiplayer > 0 || i == res_len - 1)
	{
		res[i--] = ((n % 10) * abs_multiplayer) + '0';
		n /= 10;
	}
	if (abs_multiplayer < 0)
		res[i--] = '-';
	return (res);
}
