/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexter_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:47:40 by agorski           #+#    #+#             */
/*   Updated: 2024/12/23 23:04:48 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_squote(char *t_line, t_minishell *minishell)
{
	int		i;
	char	*temp;

	i = 1;
	while (t_line[i] && t_line[i] != '\'')
		i++;
	temp = ft_substr(t_line, 1, i - 1);
	minishell->l_hdr = ft_strjoin(minishell->l_hdr, temp);
	free(temp);
	if (ft_strchr(SYMBOLS_C, t_line[i + 1]))
	{
		minishell->lexter_tab = ft_addline(minishell, minishell->l_hdr, CMD);
		minishell->l_hdr = NULL;
	}
	return (i + 1);
}

int	ft_dquote(char *t_line, t_minishell *minishell)
{
	int		i;
	char	*temp;
	char	*result;

	i = 1;
	while (t_line[i] && t_line[i] != '\"')
		i++;
	temp = ft_substr(t_line, 1, i - 1);
	result = ft_d_roll(temp, minishell);
	free(temp);
	minishell->l_hdr = ft_strjoin(minishell->l_hdr, result);
	free(result);
	if (ft_strchr(SYMBOLS_C, t_line[i + 1]))
	{
		minishell->lexter_tab = ft_addline(minishell, minishell->l_hdr, CMD);
		minishell->l_hdr = NULL;
	}
	return (i + 1);
}
