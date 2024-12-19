/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:23:49 by agorski           #+#    #+#             */
/*   Updated: 2024/12/19 13:45:09 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_shell_free(t_minishell *minishell)
{
	tab_free(minishell->lexter_tab);
	free(minishell->line);
	env_free(minishell->m_env);
}

void	tab_free(char **lexter_tab)
{
	int	i;

	if (lexter_tab == NULL)
		return ;
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

void env_free(t_list *env)
{
	t_list	*tmp;
	char	**env_vars;

	while (env)
	{
		tmp = env;
		env_vars = (char **)env->content;
		if (env_vars)
		{
			free(env_vars[0]);
			free(env_vars[1]);
			free(env_vars);
		}
		env = env->next;
		free(tmp);
	}
}