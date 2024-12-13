/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:30:52 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/04 17:33:49 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char c1 = 'a';
	char c2 = 'Z';
	char c3 = '5';
	char c4 = '$';

	printf("ft_isalnum('%c') = %d\n", c1, ft_isalnum(c1));
	printf("ft_isalnum('%c') = %d\n", c2, ft_isalnum(c2));
	printf("ft_isalnum('%c') = %d\n", c3, ft_isalnum(c3));
	printf("ft_isalnum('%c') = %d\n", c4, ft_isalnum(c4));

	return (0);
}*/