/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_config.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:31:15 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/17 17:36:37 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_single_format.h"

t_foramt_config	get_default_conf(void);
void			parse_flag(const char *format, t_foramt_config *conf);

t_foramt_config	parse_format_config(const char *format)
{
	t_foramt_config	conf;

	conf = get_default_conf();
	while (ft_strchr("#0- +", *format))
		parse_flag(format++, &conf);
	if (ft_isdigit(*format))
		conf.min_width = ft_atoi(format);
	format = skip_digits(format);
	if (*format == '.')
	{
		format++;
		conf.precision = ft_atoi(format);
		format = skip_digits(format);
	}
	conf.conversion = *format;
	return (conf);
}

t_foramt_config	get_default_conf(void)
{
	t_foramt_config	conf;

	conf.alt_form = 0;
	conf.zero_padding = 0;
	conf.left_adjusted = 0;
	conf.space_before_pos = 0;
	conf.force_sign = 0;
	conf.min_width = -1;
	conf.precision = -1;
	conf.conversion = 0;
	return (conf);
}

void	parse_flag(const char *format, t_foramt_config *conf)
{
	if (*format == '#')
		conf->alt_form = 1;
	else if (*format == '0')
		conf->zero_padding = 1;
	else if (*format == '-')
		conf->left_adjusted = 1;
	else if (*format == ' ')
		conf->space_before_pos = 1;
	else if (*format == '+')
		conf->force_sign = 1;
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_foramt_config	conf;

// 	conf = parse_format_config(" -234.11x");
// 	printf("alt_form: %d\n", conf.alt_form);
// 	printf("zero_padding: %d\n", conf.zero_padding);
// 	printf("left_adjusted: %d\n", conf.left_adjusted);
// 	printf("space_before_pos: %d\n", conf.space_before_pos);
// 	printf("force_sign: %d\n", conf.force_sign);
// 	printf("min_width: %d\n", conf.min_width);
// 	printf("precision: %d\n", conf.precision);
// 	printf("conversion: %c\n", conf.conversion);
// 	return (0);
// }
