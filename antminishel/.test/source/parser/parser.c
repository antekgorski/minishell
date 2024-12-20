/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:23:41 by agorski           #+#    #+#             */
/*   Updated: 2024/12/19 16:15:46 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// check if the quote is closed
// if not it will print the error message
// run lexical analysis

void	parse(t_minishell *minishell)
{
	if (check_quote(minishell) == 1)
		return ;
	minishell->lexter_tab = NULL;
	ft_lexter(minishell);
	if (minishell->lexter_tab)
	{
		minishell->f_signal = e_bild(minishell->lexter_tab, minishell);
	}
	if (minishell->lexter_tab != NULL)
		tab_free(minishell->lexter_tab);
}
