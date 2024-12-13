/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:29:08 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/20 17:52:45 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}

// (17) Declare 'b' to store the total number of bytes to allocate.
// (18) Declare 'p' as to store the address of the allocated memory.
// (20-24) If 'nmemb' or 'n' is 0, or overflow return NULL.
// (25) Calculate total bytes to allocate.
// (26) Allocate 'b' biter of memory nd assign to adres of 'p'.
// (27-28) If allocation fails return NULL.
// (30) If alocation was succesfull set allocated memory to 0.
// (31)	Return pointer to the allocated memory and zero-initialized memory.

/*
//#include <stdio.h>

int	main(void)
{
	int *arr = ft_calloc(3, sizeof(int));
	char *str = ft_calloc(5, sizeof(char));

	printf("arr: %p\n", arr);
	printf("str: %p\n", str);

	return (0);
}*/