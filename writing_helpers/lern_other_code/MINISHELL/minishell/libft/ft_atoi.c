/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:01:43 by fursini           #+#    #+#             */
/*   Updated: 2023/01/25 23:27:33 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		num;
	int		i;
	int		minus;

	num = 0;
	i = 0;
	minus = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		minus++;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (minus % 2 == 0)
		return (num);
	return (num *= -1);
}

// int main()
// {
// 	char a[] = "-2147483648";
// 	int x = atoi(a);
// 	int y = ft_atoi(a);
// 	printf("%d\n", x);
// 	printf("%d\n", y);
// }
