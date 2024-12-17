/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:23:41 by agorski           #+#    #+#             */
/*   Updated: 2024/12/17 12:10:33 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse(t_minishell *minishell)
{
	int i;
	i = 0;
	if (check_quote(minishell) == 1)
		return ;
	minishell->lexter_tab = NULL;
	//minishell->lexter_tab[0] = NULL;
	ft_lexter(minishell);
	if (minishell->lexter_tab)
	{
		while (minishell->lexter_tab[i])
		{
			printf("%s\n", minishell->lexter_tab[i++]);
		}
	}
	if(minishell->lexter_tab != NULL)
		tab_free(minishell->lexter_tab);
}