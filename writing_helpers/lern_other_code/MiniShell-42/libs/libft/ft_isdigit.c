/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:24:55 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/04 17:38:34 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>

int	main(void) {

	char c1 = '3';
	char c2 = 'b';
	char c3 = '9';
	char c4 = '$';

	printf("ft_isdigit('%c') = %d\n", c1, ft_isdigit(c1));
	printf("ft_isdigit('%c') = %d\n", c2, ft_isdigit(c2));
	printf("ft_isdigit('%c') = %d\n", c3, ft_isdigit(c3));
	printf("ft_isdigit('%c') = %d\n", c4, ft_isdigit(c4));

	return (0);
}
*/