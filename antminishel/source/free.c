/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:23:49 by agorski           #+#    #+#             */
/*   Updated: 2024/12/17 11:55:24 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_shell_free(t_minishell *minishell)
{
	int	i;

	i = 0;
	while (minishell->lexter_tab[i])
	{
		free(minishell->lexter_tab[i]);
		i++;
	}
	free(minishell->lexter_tab);
	free(minishell->line);
}

void	tab_free(char **lexter_tab)
{
	if (lexter_tab == NULL)
		return ;
	int i;

	i = 0;
	while (lexter_tab[i] && lexter_tab[i] != NULL)
	{
		free(lexter_tab[i]);
		lexter_tab[i] = NULL;

		i++;
	}
	free(lexter_tab);
	lexter_tab = NULL;
}