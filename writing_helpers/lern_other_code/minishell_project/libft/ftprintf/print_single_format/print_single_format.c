/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_single_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:26:42 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/16 18:09:37 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_single_format.h"

int	print_single_format(const char *format, va_list *args)
{
	t_foramt_config	conf;

	conf = parse_format_config(++format);
	if (conf.conversion == 'i' || conf.conversion == 'd')
		return (print_int_conv(conf, args));
	if (conf.conversion == 'u')
		return (print_uint_conv(conf, args));
	if (conf.conversion == 'x')
		return (print_lhex_conv(conf, args));
	if (conf.conversion == 'X')
		return (print_uhex_conv(conf, args));
	if (conf.conversion == 'c')
		return (print_char_conv(conf, args));
	if (conf.conversion == 's')
		return (print_str_conv(conf, args));
	if (conf.conversion == 'p')
		return (print_ptr_conv(conf, args));
	if (conf.conversion == '%')
		return (print_pct_conv(conf, args));
	return (0);
}
