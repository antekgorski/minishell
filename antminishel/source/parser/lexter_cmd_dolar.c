/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexter_cmd_dolar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:05:29 by agorski           #+#    #+#             */
/*   Updated: 2024/12/22 18:43:14 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_comend(char *t_line, t_minishell *minishell)
{
	int		i;
	char	*temp_arg;
	char	*result;

	i = 0;
	while (t_line[i] && !ft_strchr(SYMBOLS_D, t_line[i]))
		i++;
	temp_arg = ft_substr(t_line, 0, i);
	result = ft_d_roll(temp_arg, minishell);
	free(temp_arg);
	minishell->l_hdr = ft_strjoin(minishell->l_hdr, result);
	free(result);
	if (ft_strchr(SYMBOLS_C, t_line[i]))
	{
		minishell->lexter_tab = ft_addline(minishell, minishell->l_hdr, CMD);
		minishell->l_hdr = NULL;
	}
	return (i);
}
