/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:55:01 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:20:47 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @brief Writes an integer to the specified file descriptor as a string.
 *
 * The function converts the integer `n` to its string representation 
 * and writes it to the file descriptor `fd`. It handles special cases 
 * for zero, negative numbers, and the minimum integer value.
 *
 * @param n The integer to be written.
 * @param fd The file descriptor to which the integer will be written. 
 *           Common values include 1 for standard output and 2 for 
 *           standard error.
 * 
 * @note The function does not perform error checking on the write operations. 
 *       If the write fails, the behavior is not defined. The function also 
 *       correctly handles the edge case of `-2147483648`, which cannot 
 *       be represented as a positive number due to integer overflow.
 */
static void	write_function(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write_function('-', fd);
		write_function('2', fd);
		n = 147483648;
	}
	if (0 > n)
	{
		write_function('-', fd);
		n *= (-1);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		write_function(n + '0', fd);
}
