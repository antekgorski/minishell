/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:23:41 by agorski           #+#    #+#             */
/*   Updated: 2024/12/16 23:38:37 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse(t_minishell *minishell)
{
	minishell->lexter_tab = NULL;
	int i;
	i = 0;
	if (check_quote(minishell) == 1)
		return ;
	ft_lexter(minishell);
	if (minishell->lexter_tab)
	{
		while (minishell->lexter_tab[i])
		{
			printf("%s\n", minishell->lexter_tab[i++]);
		}
	}
	tab_free(minishell->lexter_tab);
}