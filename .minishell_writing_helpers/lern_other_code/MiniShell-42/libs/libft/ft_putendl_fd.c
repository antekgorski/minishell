/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:09:14 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/04 20:11:01 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	if (s != NULL)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}

/*
int	main(void)
{
	// Test writing a string followed by a newline to stdout
	ft_putendl_fd("Hello, World!", 1);

	// Test writing a string followed by a newline to stderr
	ft_putendl_fd("This is an error message.", 2);

	return (0);
}*/