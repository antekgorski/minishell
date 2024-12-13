/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_on_space_pading.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:58:49 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/17 17:43:02 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_single_format.h"

int	do_on_space_pading(t_foramt_config conf, char *str, int len)
{
	int	i;

	if (conf.left_adjusted)
		ft_putstr_fd(str, 1);
	i = -1;
	while (++i < conf.min_width - len)
		ft_putchar_fd(' ', 1);
	if (!conf.left_adjusted)
		ft_putstr_fd(str, 1);
	free(str);
	return (conf.min_width);
}
