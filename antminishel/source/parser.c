/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:23:41 by agorski           #+#    #+#             */
/*   Updated: 2024/12/19 13:33:42 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// check if the quote is closed
// if not it will print the error message
//run lexical analysis

void	parse(t_minishell *minishell)
{
	// int	i;

	// i = 0;
	if (check_quote(minishell) == 1)
		return ;
	minishell->lexter_tab = NULL;
	ft_lexter(minishell);
	if (minishell->lexter_tab)
	{
		// while (minishell->lexter_tab[i])
		// {
		// 	printf("%s\n", minishell->lexter_tab[i++]);
		// }
		execute_command(minishell->lexter_tab);
	}
	if (minishell->lexter_tab != NULL)
		tab_free(minishell->lexter_tab);
}
