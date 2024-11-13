/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:38:13 by agorski           #+#    #+#             */
/*   Updated: 2024/11/07 13:17:20 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_string(char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}
