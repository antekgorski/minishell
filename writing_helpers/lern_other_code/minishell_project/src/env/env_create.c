/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:14:46 by sehosaf           #+#    #+#             */
/*   Updated: 2024/06/19 21:13:47 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

/**
 * @brief Creates a new environment variable.
 * @details If the variable already exists, it will be overwritten.
 * @param env The environment variable list of the shell structure
 * @param key_value The key and value of the environment variable as a string.
 * @return The exit status
*/
int	create_env_var(t_env **env, const char *key_value)
{
	t_env	*new_node;
	t_env	*last_node;
	char	**key_val;
	t_env	*existing_node;

	if (!is_valid_env_var(key_value))
		return (EXIT_FAILURE);
	key_val = split_key_value(key_value, '=');
	if (key_val[0] == NULL || key_val[1] == NULL)
		return (free_key_val(key_val, false));
	existing_node = get_env_node(*env, key_val[0]);
	if (existing_node)
		return (overwrite_var(existing_node, key_val));
	new_node = create_env_node(key_val);
	if (new_node == NULL)
		return (free_key_val(key_val, false));
	last_node = get_last_node(*env);
	if (last_node == NULL)
		*env = new_node;
	else
		last_node->next = new_node;
	return (free_key_val(key_val, true));
}

/**
 * @brief Creates a new node for the environment variable list.
 * @param key_value The key and value pair of the environment variable
 * @return The new node if successful, NULL otherwise
*/
t_env	*create_env_node(char **key_value)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (new_node == NULL)
		return (NULL);
	new_node->key = ft_strdup(key_value[0]);
	new_node->value = ft_strdup(key_value[1]);
	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}
