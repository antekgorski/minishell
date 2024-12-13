/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:09:25 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/18 13:13:25 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (i < n)
		p[i++] = 0;
}

// (17)Define 'i' as size_t variable to keep track of current index.
// (18)Declare 'p' as a pointer to char to work with the byte-level data.
// (20)Initialize i to 0 as start value.
// (21)Assigne '(char *)s' to 'p' for performing byte operations.
// (22-23)Use a while loop to iterate
//	over each byte of the specified memory area.
// (22)Continue looping as long as i is less than n.
// (23)Set byte current 'p' to 0 and then
//	increment 'i' to move to the next byte.

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	test[3] = "hdf";
	char	test1[4] = "hdfa";

	ft_bzero(test, 2);
	printf("FT_bzero = %s \n ", test);
	bzero(test1, 2);
	printf("Oryginal bzero = %s \n ", test1);

	return (0);
}*/