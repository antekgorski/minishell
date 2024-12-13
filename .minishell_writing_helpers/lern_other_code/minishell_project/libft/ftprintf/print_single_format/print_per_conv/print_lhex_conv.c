/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lhex_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:12:19 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/20 20:39:08 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_single_format.h"

static void	helper(t_foramt_config conf, char **num, int len)
{
	char	*tmp;
	int		is_zero;

	is_zero = (**num == '0');
	if (conf.alt_form && !is_zero)
		conf.min_width -= 2;
	pad_zeros(conf, num, len, 0);
	if (conf.alt_form && !is_zero)
	{
		conf.min_width += 2;
		tmp = ft_strjoin("0x", *num);
		free(*num);
		*num = tmp;
	}
}

int	print_lhex_conv(t_foramt_config conf, va_list *args)
{
	char	*num;
	int		len;

	num = ft_utobase(va_arg(*args, unsigned int), "0123456789abcdef");
	if (!num)
		return (0);
	len = ft_strlen(num);
	if (conf.precision == 0 && num[0] == '0')
	{
		num[0] = 0;
		len = 0;
	}
	else
		helper(conf, &num, len);
	len = ft_strlen(num);
	if (conf.min_width > len)
		return (do_on_space_pading(conf, num, len));
	ft_putstr_fd(num, 1);
	free(num);
	return (len);
}
