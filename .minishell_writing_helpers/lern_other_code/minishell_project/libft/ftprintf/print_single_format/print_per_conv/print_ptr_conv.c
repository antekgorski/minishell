/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:48:14 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/20 17:26:22 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_single_format.h"

int	print_ptr_conv(t_foramt_config conf, va_list *args)
{
	void	*ptr;
	char	*str;
	char	*tmp;
	int		len;

	ptr = va_arg(*args, void *);
	if (!ptr)
		str = ft_strdup("(nil)");
	else
	{
		tmp = ft_utobase((uintptr_t)ptr, "0123456789abcdef");
		str = ft_strjoin("0x", tmp);
		free(tmp);
	}
	len = ft_strlen(str);
	if (conf.min_width > len)
		return (do_on_space_pading(conf, str, len));
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
