/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pct_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:30:32 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/17 18:32:45 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_single_format.h"

int	print_pct_conv(t_foramt_config conf, va_list *args)
{
	(void)conf;
	(void)args;
	ft_putchar_fd('%', 1);
	return (1);
}
