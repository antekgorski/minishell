/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:23:49 by agorski           #+#    #+#             */
/*   Updated: 2024/12/16 19:31:59 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_shell_free(t_minishell *minishell)
{
    int i;

    i = 0;
    while (minishell->lexter_tab[i])
    {
        free(minishell->lexter_tab[i]);
        i++;
    }
    free(minishell->lexter_tab);
    free(minishell->line);
}

void  lexter_free(t_minishell *minishell)
{
    if(minishell->lexter_tab == NULL)
        return ;
    int i;

    i = 0;
    while (minishell->lexter_tab[i])
    {
        free(minishell->lexter_tab[i]);
        i++;
    }
    free(minishell->lexter_tab);
    minishell->lexter_tab = NULL;
}