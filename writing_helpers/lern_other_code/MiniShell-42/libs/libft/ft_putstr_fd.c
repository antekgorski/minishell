/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:04:38 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/18 13:15:07 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	write(fd, s, i);
}

/*
int	main(void)
{
	ft_putstr_fd("Hello, stdout!", 1);
	write(1, "\n", 1);
	ft_putstr_fd("Hello, stderr!", 2);
	write(2, "\n", 2);
	return (0);
}
*/