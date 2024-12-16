/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:23:41 by agorski           #+#    #+#             */
/*   Updated: 2024/12/16 12:45:47 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse(t_minishell *minishell)
{
	int i;
	i = 0;
	check_quote(minishell);
	ft_lexter(minishell);
	if (minishell->lexter_tab)
	{
		while (minishell->lexter_tab[i])
		{
			printf("%s\n", minishell->lexter_tab[i++]);
		}
	}
	ft_shell_free(minishell);
}