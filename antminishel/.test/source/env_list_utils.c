/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:42:53 by agorski           #+#    #+#             */
/*   Updated: 2024/12/19 15:52:16 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
