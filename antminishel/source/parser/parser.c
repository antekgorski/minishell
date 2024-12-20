/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:23:41 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 13:37:04 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parser_test(t_minishell *minishell)
{
	int	i;

	i = 0;
	while (minishell->lexter_tab[i])
	{
		printf("%s\t%i\n", minishell->lexter_tab[i], *(int *)minishell->token_list->content);
		i++;
		minishell->token_list = minishell->token_list->next;
	}
}

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
		tab_free(&minishell->lexter_tab);
	if (minishell->token_list != NULL)
		ft_token_free(&minishell->token_list);
}
