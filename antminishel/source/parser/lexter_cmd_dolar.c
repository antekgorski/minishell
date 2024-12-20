/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexter_cmd_dolar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:05:29 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 16:01:05 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_comend(char *temp_line, t_minishell *minishell)
{
	char	*temp_arg;
	int		i;

	i = 0;
	while (temp_line[i] && !ft_strchr(SYMBOLS, temp_line[i]))
		i++;
	temp_arg = ft_substr(temp_line, 0, i);
	minishell->lexter_tab = ft_addline(minishell, temp_arg, CMD);
	return (i);
}

int	ft_dolar(char *temp_line, t_minishell *minishell)
{
	int		i;
	char	*temp_arg;
	char	*temp;
	char	*r_dolar;

	i = 1;
	while (temp_line[i] && !ft_strchr(SYMBOLS, temp_line[i]))
		i++;
	temp_arg = ft_substr(temp_line, 0, i);
	if (ft_strcmp(temp_arg, "$") == 0)
	{
		minishell->lexter_tab = ft_addline(minishell, temp_arg, DOLAR);
		return (i);
	}
	temp = ft_strtrim(temp_arg, "$ \t");
	free(temp_arg);
	r_dolar = ft_get_env(minishell->m_env, temp);
	free(temp);
	if (r_dolar == NULL)
		return (i);
	temp = malloc(ft_strlen(r_dolar) + 1);
	ft_strlcpy(temp, r_dolar, ft_strlen(r_dolar) + 1);
	r_dolar = NULL;
	minishell->lexter_tab = ft_addline(minishell, temp, DOLAR);
	return (i);
}
