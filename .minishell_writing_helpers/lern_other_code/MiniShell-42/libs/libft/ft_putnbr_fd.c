/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:13:50 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/18 13:15:49 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd((nb % 10) + '0', fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
}

// (16) Begin function to write an integer to a file descriptor.
// (18) Use a long to handle potentially large or negative numbers.
// (20) Convert int to long to safely manage negative values.
// (21-25) If the number is negative,
//	write a '-' sign and make the number positive.
// (26-30) If the number has more than one digit,
//	recursively write its digits from left to right.
// (31-32) For single-digit numbers, just write the digit.

/*
#include <stdio.h>

void	test_ft_putnbr_fd(void)
{
	int	test_numbers[] = {0, -1, 2147483647, -2147483648};
	int	num_tests;

	num_tests = sizeof(test_numbers) / sizeof(test_numbers[0]);
	printf("Testing ft_putnbr_fd with stdout:\n");
	for (int i = 0; i < num_tests; i++)
	{
		printf("Number: ");
		ft_putnbr_fd(test_numbers[i], 1); // 1 is the file descriptor for stdout
		printf("\n");
			// Move to the next line after the output
	}
}

int	main(void)
{
	test_ft_putnbr_fd();
	return (0);
}
*/