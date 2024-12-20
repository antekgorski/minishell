/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexter_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:47:40 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 18:30:05 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_squote(char *temp_line, t_minishell *minishell)
{
	int		i;
	char	*temp_arg;
	char	*temp;

	i = 1;
	while (temp_line[i] && temp_line[i] != '\'')
		i++;
	temp_arg = ft_substr(temp_line, 1, i - 1);
	temp = ft_strtrim(temp_arg, " \t");
	free(temp_arg);
	minishell->lexter_tab = ft_addline(minishell, temp, SQUOTE);
	return (i + 1);
}

void	ft_d_roll(char **temp_arg, t_minishell *minishell)
{
	char	**temp_tab;
	char	*r_dolar;
	int		i;

	i = 0;
	temp_tab = ft_split(*temp_arg, '$');
	while (temp_tab[i])
	{
		r_dolar = ft_get_env(minishell->m_env,temp_tab[i]);
		printf("r_dolar:%s\n", r_dolar);
		i++;
	}
}

int	ft_dquote(char *temp_line, t_minishell *minishell)
{
	int		i;
	char	*temp_arg;
	char	*temp;

	i = 1;
	while (temp_line[i] && temp_line[i] != '\"')
		i++;
	temp_arg = ft_substr(temp_line, 1, i - 1);
	temp = ft_strtrim(temp_arg, " \t");
	free(temp_arg);
	ft_d_roll(&temp, minishell);
	minishell->lexter_tab = ft_addline(minishell, temp, DQUOTE);
	return (i + 1);
}
