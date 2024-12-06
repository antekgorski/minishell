/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:47:43 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/07 11:49:22 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*
//#include <stdio.h>

int	main(void)
{
	wchar_t	c2;

	char c1 = 'a'; // ASCII character
	c2 = L'€';
	printf("ft_isascii('%c') = %d\n", c1, ft_isascii(c1));
	printf("ft_isascii('%c') = %d\n", c2, ft_isascii(c2));
	return (0);
}
*/