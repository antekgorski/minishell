/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexter_cmd_dolar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:05:29 by agorski           #+#    #+#             */
/*   Updated: 2024/12/21 22:24:28 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_comend(char *temp_line, t_minishell *minishell)
{
	int		i;
	char	*temp_arg;
	char	*result;

	i = 0;
	while (temp_line[i] && !ft_strchr(SYMBOLS_D, temp_line[i]))
		i++;
	temp_arg = ft_substr(temp_line, 0, i);
	result = ft_d_roll(temp_arg, minishell);
	free(temp_arg);
	minishell->lexter_tab = ft_addline(minishell, result, CMD);
	return (i);
}
