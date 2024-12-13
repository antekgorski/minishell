/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:42:49 by sehosaf           #+#    #+#             */
/*   Updated: 2024/07/17 11:35:00 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

/**
 * @brief Gets the environment variable node with the specified key.
 * @param env The environment variable list of the shell structure
 * @param key The key of the environment variable
 * @return The node with the specified key
*/
t_env	*get_env_node(t_env *env, const char *key)
{
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

/**
 * @brief Gets the last node of the environment variable list.
 * @param env The environment variable list of the shell structure
 * @return The last node of the list
*/
t_env	*get_last_node(t_env *env)
{
	t_env	*last_node;

	last_node = env;
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}

/**
 * @brief Splits a string into two parts using a delimiter.
 * @param str The string to split
 * @param c The delimiter
 * @return The two parts of the string
*/
char	**split_key_value(const char *str, char c)
{
	char	**result;
	char	*index;

	result = (char **)malloc(sizeof(char *) * 3);
	if (!result)
		return (perror(ERR_MALLOC), NULL);
	index = ft_strchr(str, c);
	if (index)
	{
		result[0] = ft_substr(str, 0, index - str);
		result[1] = ft_strdup(index + 1);
	}
	else
	{
		result[0] = ft_strdup(str);
		result[1] = NULL;
	}
	result[2] = NULL;
	return (result);
}

/**
 * @brief Checks if a string is a valid environment variable.
 * @param str The string to check
 * @return true if the string is a valid environment variable, false otherwise
*/
bool	is_valid_env_var(const char *str)
{
	char	**key_val;
	size_t	i;

	key_val = split_key_value(str, '=');
	if (key_val == NULL)
		return (false);
	if (key_val[0] == NULL || key_val[1] == NULL)
		return (free_key_val(key_val, false), false);
	i = 0;
	while (key_val[0][i])
	{
		if (!ft_isalnum(key_val[0][i]) && key_val[0][i] != '_')
			return (free_key_val(key_val, false), false);
		i++;
	}
	return (free_key_val(key_val, true), true);
}

/**
 * @brief Gets the size of the environment variable list.
 * @param env The environment variable list of the shell structure
 * @return The size of the list
 */
int	get_env_size(t_env *env)
{
	int		count;
	t_env	*tmp;

	count = 0;
	tmp = env;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
