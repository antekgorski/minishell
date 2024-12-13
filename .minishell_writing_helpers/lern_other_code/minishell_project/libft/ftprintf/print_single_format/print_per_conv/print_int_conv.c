/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:36:46 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/17 18:31:42 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_single_format.h"

void	add_sign(t_foramt_config conf, char **num, int is_neg);

int	print_int_conv(t_foramt_config conf, va_list *args)
{
	char	*num;
	int		is_neg;
	int		len;

	num = ft_itoa(va_arg(*args, int));
	if (!num)
		return (0);
	len = ft_strlen(num);
	is_neg = 0;
	if (num[0] == '-')
		ft_memmove(num, num + ++is_neg, len--);
	if (conf.precision == 0 && num[0] == '0')
	{
		num[0] = 0;
		len = 0;
	}
	else
		pad_zeros(conf, &num, len, is_neg);
	add_sign(conf, &num, is_neg);
	len = ft_strlen(num);
	if (conf.min_width > len)
		return (do_on_space_pading(conf, num, len));
	ft_putstr_fd(num, 1);
	free(num);
	return (len);
}

void	add_sign(t_foramt_config conf, char **num, int is_neg)
{
	char	*tmp;

	if (is_neg)
	{
		tmp = ft_strjoin("-", *num);
		free(*num);
		*num = tmp;
	}
	else if (conf.force_sign)
	{
		tmp = ft_strjoin("+", *num);
		free(*num);
		*num = tmp;
	}
	else if (conf.space_before_pos)
	{
		tmp = ft_strjoin(" ", *num);
		free(*num);
		*num = tmp;
	}
}
