/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/29 17:24:12 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int	is_option_n(const char *str)
{
	int	i;

	if (str[0] != '-')
		return (0);
	i = 1;
	if (str[i] != 'n')
		return (0);
	while (str[i] == 'n')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	ft_echo(char **args)
{
	int	i;
	int	new_line;
	int	len;

	i = 1;
	new_line = 1;
	while (args[i] && is_option_n(args[i]))
	{
		new_line = 0;
		i++;
	}
	while (args[i])
	{
		len = ft_strlen(args[i]);
		write(STDOUT_FILENO, args[i], len);
		if (args[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	if (new_line)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
