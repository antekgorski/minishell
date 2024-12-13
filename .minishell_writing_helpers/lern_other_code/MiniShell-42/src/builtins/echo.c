/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:15:20 by mjakowic          #+#    #+#             */
/*   Updated: 2024/08/08 16:49:55 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	size_args(char **as)
{
	int	size;

	size = 0;
	while (as[size])
		size++;
	return (size);
}

int	md_echo(char **as)
{
	int	i;
	int	n_option;

	i = 1;
	n_option = 0;
	if (size_args(as) > 1)
	{
		while (as[i] && ft_strcmp(as[i], "-n") == 0)
		{
			n_option = 1;
			i++;
		}
		while (as[i])
		{
			ft_putstr_fd(as[i], 1);
			if (as[i + 1] && as[i][0])
				write(1, " ", 1);
			i++;
		}
	}
	if (n_option == 0)
		write(1, "\n", 1);
	return (0);
}
