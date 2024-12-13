/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:36:46 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/20 18:06:56 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_single_format.h"

int	print_uint_conv(t_foramt_config conf, va_list *args)
{
	char	*num;
	int		len;

	num = ft_utoa(va_arg(*args, unsigned int));
	if (!num)
		return (0);
	len = ft_strlen(num);
	if (conf.precision == 0 && num[0] == '0')
	{
		num[0] = 0;
		len = 0;
	}
	else
		pad_zeros(conf, &num, len, 0);
	len = ft_strlen(num);
	if (conf.min_width > len)
		return (do_on_space_pading(conf, num, len));
	ft_putstr_fd(num, 1);
	free(num);
	return (len);
}
