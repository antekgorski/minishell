/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:35:12 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/18 13:14:58 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int	main(void)
{
	// Test writing to stdout
	ft_putchar_fd('H', 1);  // Should print 'H' to the terminal
	ft_putchar_fd('i', 1);  // Should print 'i' to the terminal
	ft_putchar_fd('\n', 1); // Should move to a new line in the terminal
	// Test writing to stderr
	ft_putchar_fd('E', 2);  // Should print 'E' as an error message
	ft_putchar_fd('r', 2);  // Should print 'r' as an error message
	ft_putchar_fd('r', 2);  // Should print 'r' as an error message
	ft_putchar_fd('o', 2);  // Should print 'o' as an error message
	ft_putchar_fd('r', 2);  // Should print 'r' as an error message
	ft_putchar_fd('\n', 2);
		// Should move to a new line in the error message output
	return (0);
}
*/