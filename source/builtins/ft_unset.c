/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2024/12/20 19:12:30 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	free_env_node(t_list *node)
{
	char	**env_vars;

	if (!node || !node->content)
		return ;
	env_vars = (char **)node->content;
	if (env_vars[0])
		free(env_vars[0]);
	if (env_vars[1])
		free(env_vars[1]);
	free(env_vars);
	free(node);
}

int	ft_unset(t_minishell *minishell, const char *name)
{
	t_list	*current;
	t_list	*prev;
	char	**env_vars;

	if (!name || !(minishell->m_env))
		return (1);
	current = minishell->m_env;
	prev = NULL;
	while (current)
	{
		env_vars = (char **)current->content;
		if (ft_strcmp(env_vars[0], name) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				minishell->m_env = current->next;
			free_env_node(current);
			return (0);
		}
		prev = current;
		current = current->next;
	}
	return (0);
}
