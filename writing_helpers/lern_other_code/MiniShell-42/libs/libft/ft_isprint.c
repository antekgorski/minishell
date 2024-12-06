/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:51:13 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/04 18:37:12 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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

	c1 = ' ';
	c2 = 'a';
	c3 = 'Z';
	c4 = '\n';
	printf("ft_isprint('%c') = %d\n", c1, ft_isprint(c1));
	printf("ft_isprint('%c') = %d\n", c2, ft_isprint(c2));
	printf("ft_isprint('%c') = %d\n", c3, ft_isprint(c3));
	printf("ft_isprint('%c') = %d\n", c4, ft_isprint(c4));
	return (0);
}
*/