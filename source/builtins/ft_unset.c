/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/24 10:43:30 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"
/**
 * @brief Frees the memory allocated for an environment variable node.
 *
 * @param node Pointer to the list node to be freed.
 */
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

/**
 * @brief Removes a single environment variable from the list.
 *
 * @param minishell Pointer to the minishell structure.
 * @param name Name of the environment variable to be removed.
 * @return Returns 0 on success, 1 on error.
 */
static int	ft_unset_single(t_minishell *minishell, const char *name)
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

/**
 * @brief Unsets multiple environment variables.
 *
 * @param minishell Pointer to the minishell structure.
 * @param name Array of names of the environment variables to be removed.
 * @return Returns 0 on success, 1 on error.
 */
int	ft_unset(t_minishell *minishell, char **name)
{
	int	i;
	int	status;

	status = 0;
	if (!name || !minishell->m_env)
		return (1);
	i = 0;
	while (name[i])
	{
		if (ft_unset_single(minishell, name[i]) != 0)
			status = 1;
		i++;
	}
	return (status);
}
