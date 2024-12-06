/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:00:18 by fursini           #+#    #+#             */
/*   Updated: 2023/01/26 00:46:37 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printer_int(long ml10, int counter, long nblong, int fd)
{
	char	c;
	long	x;

	ml10 /= 10;
	while (counter > 0)
	{
		x = nblong;
		c = x / ml10 % 10 + '0';
		write(fd, &c, 1);
		counter --;
		ml10 /= 10;
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	int		e;
	long	nbl;
	long	mlt;
	long	nbl2;

	e = 0;
	mlt = 1;
	nbl = nb;
	if (nbl < 0)
	{
		nbl *= -1;
		write(fd, "-", 1);
	}
	nbl2 = nbl;
	while (nbl2 >= 1)
	{
		mlt *= 10;
		nbl2 /= 10;
		e++;
	}
	printer_int(mlt, e, nbl, fd);
	if (nbl == 0)
		write(fd, "0", 1);
}
