/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:42:53 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 15:15:59 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief 	Searches for an environment variable by key.
 * @param head A pointer to the head of the linked list.
 * @param key The key to search for in the linked list.
 * @return A pointer to the value of the environment variable if found,
 * 	   or NULL if the key is not found.
 */
char	*ft_get_env(t_list *head, char *key)
{
	t_list	*current;
	char	**env_vars;

	current = head;
	while (current != NULL)
	{
		env_vars = (char **)current->content;
		if (ft_strncmp(env_vars[0], key, ft_strlen(key)) == 0)
			return (env_vars[1]);
		current = current->next;
	}
	return (NULL);
}

t_list	*ft_find_env(t_list *head, char *key)
{
	t_list	*current;
	char	**env_vars;

	current = head;
	while (current != NULL)
	{
		env_vars = (char **)current->content;
		if (ft_strncmp(env_vars[0], key, ft_strlen(key)) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}
