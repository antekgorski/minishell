/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:20:01 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/04 17:38:00 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char	c1;
	char	c2;
	char	c3;
	char	c4;

	c1 = 'a';
	c2 = 'B';
	c3 = '4';
	c4 = '%';
	printf("ft_isalpha('%c') = %d\n", c1, ft_isalpha(c1));
	printf("ft_isalpha('%c') = %d\n", c2, ft_isalpha(c2));
	printf("ft_isalpha('%c') = %d\n", c3, ft_isalpha(c3));
	printf("ft_isalpha('%c') = %d\n", c4, ft_isalpha(c4));
	return (0);
}
*/