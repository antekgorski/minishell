/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexter_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:47:40 by agorski           #+#    #+#             */
/*   Updated: 2024/12/21 22:33:13 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_squote(char *temp_line, t_minishell *minishell)
{
	int		i;
	char	*temp;

	i = 1;
	while (temp_line[i] && temp_line[i] != '\'')
		i++;
	temp = ft_substr(temp_line, 1, i - 1);
	minishell->lexter_tab = ft_addline(minishell, temp, SQUOTE);
	return (i + 1);
}

int	ft_dquote(char *temp_line, t_minishell *minishell)
{
	int		i;
	char	*temp;
	char	*result;

	i = 1;
	while (temp_line[i] && temp_line[i] != '\"')
		i++;
	temp = ft_substr(temp_line, 1, i - 1);
	result = ft_d_roll(temp, minishell);
	free(temp);
	minishell->lexter_tab = ft_addline(minishell, result, DQUOTE);
	return (i + 1);
}
