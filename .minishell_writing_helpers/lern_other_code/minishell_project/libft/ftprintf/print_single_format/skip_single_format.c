/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_single_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:19:27 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/16 14:08:37 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_single_format.h"

const char	*skip_flags(const char *str);
const char	*skip_digits(const char *str);
const char	*skip_precision(const char *str);
const char	*skip_conversion(const char *str);

const char	*skip_single_format(const char *str)
{
	str++;
	str = skip_flags(str);
	str = skip_digits(str);
	str = skip_precision(str);
	str = skip_conversion(str);
	return (str);
}

const char	*skip_flags(const char *str)
{
	while (ft_strchr("#0- +", *str))
		str++;
	return (str);
}

const char	*skip_digits(const char *str)
{
	while (ft_isdigit(*str))
		str++;
	return (str);
}

const char	*skip_precision(const char *str)
{
	if (*str == '.')
		str++;
	return (skip_digits(str));
}

const char	*skip_conversion(const char *str)
{
	if (ft_strchr("cspdiuxX%", *str))
		str++;
	return (str);
}
