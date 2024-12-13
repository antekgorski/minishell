/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:40:15 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/20 20:26:28 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_single_format.h"

static void	print_n_spaces(int n);

int	print_char_conv(t_foramt_config conf, va_list *args)
{
	char	c;

	c = va_arg(*args, int);
	if (conf.min_width > 1 && !conf.left_adjusted)
		print_n_spaces(conf.min_width - 1);
	ft_putchar_fd(c, 1);
	if (conf.min_width > 1 && conf.left_adjusted)
		print_n_spaces(conf.min_width - 1);
	if (conf.min_width > 1)
		return (conf.min_width);
	return (1);
}

static void	print_n_spaces(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
}
