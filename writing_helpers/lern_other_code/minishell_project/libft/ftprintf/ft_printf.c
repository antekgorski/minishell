/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:18:16 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/17 18:13:34 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			total;
	const char	*tmp;

	total = 0;
	va_start(args, format);
	while (*format)
	{
		tmp = ft_strchr(format, '%');
		if (tmp)
		{
			total += tmp - format;
			write(1, format, tmp - format);
			total += print_single_format(tmp, &args);
			format = skip_single_format(tmp);
		}
		else
		{
			total += ft_strlen(format);
			ft_putstr_fd((char *)format, 1);
			break ;
		}
	}
	va_end(args);
	return (total);
}
