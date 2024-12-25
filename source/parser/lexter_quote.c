/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexter_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:47:40 by agorski           #+#    #+#             */
/*   Updated: 2024/12/25 13:03:59 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_squote(char *t_line, t_minishell *minishell)
{
	int		i;
	char	*temp;
	char	*temp_hdr;

	i = 1;
	while (t_line[i] && t_line[i] != '\'')
		i++;
	temp = ft_substr(t_line, 1, i - 1);
	temp_hdr = ft_strjoin(minishell->l_hdr, temp);
	free(minishell->l_hdr);
	minishell->l_hdr = NULL;
	free(temp);
	temp = NULL;
	minishell->l_hdr = temp_hdr;
	temp_hdr = NULL;
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
	char	*temp_hdr;

	i = 1;
	while (t_line[i] && t_line[i] != '\"')
		i++;
	temp = ft_substr(t_line, 1, i - 1);
	result = ft_d_roll(temp, minishell);
	free(temp);
	temp_hdr = ft_strjoin(minishell->l_hdr, result);
	free(result);
	result = NULL;
	free(minishell->l_hdr);
	minishell->l_hdr = NULL;
	minishell->l_hdr = temp_hdr;
	temp_hdr = NULL;
	if (ft_strchr(SYMBOLS_C, t_line[i + 1]))
	{
		minishell->lexter_tab = ft_addline(minishell, minishell->l_hdr, CMD);
		minishell->l_hdr = NULL;
	}
	return (i + 1);
}
