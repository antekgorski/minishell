/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:15:26 by fursini           #+#    #+#             */
/*   Updated: 2024/05/25 11:41:35 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Checks if the given environment variable is valid.
 *
 * This function checks if the first character of the new_env string is an 
 * alphabet or underscore.
 * Then it checks if the rest of the characters until '=' are alphanumeric or 
 * underscore.
 *
 * @param new_env The new environment variable to be checked.
 * @return true if the environment variable is valid, false otherwise.
 */
static bool	check_valid_env(char *new_env)
{
	int	i;

	i = 0;
	if (!ft_isalpha(new_env[i]) && new_env[i] != '_')
		return (false);
	i++;
	while (new_env[i] && new_env[i] != '=')
	{
		if (!ft_isalnum(new_env[i]) && new_env[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief Finds an environment variable in the shell's environment list.
 *
 * This function iterates over the shell's environment list and compares each 
 * environment variable's key with the key of the new environment variable. 
 * If a match is found, it returns the matching environment variable.
 *
 * @param shell The shell containing the environment list.
 * @param new_env The new environment variable to be found.
 * @return A pointer to the found environment variable, or NULL if not found.
 */
t_token	*find_env(t_minishell *shell, char *new_env)
{
	t_token	*env_list;
	char	*tmp_key;
	char	*tmp_new_key;

	env_list = shell->env_list;
	tmp_new_key = get_key_value(new_env);
	while (env_list)
	{
		tmp_key = get_key_value(env_list->str);
		if (ft_strcmp(tmp_new_key, tmp_key) == 0)
		{
			check_free(tmp_key);
			check_free(tmp_new_key);
			return (env_list);
		}
		env_list = env_list->next;
		check_free(tmp_key);
	}
	check_free(tmp_new_key);
	return (NULL);
}

/**
 * @brief Updates an environment variable in the shell's environment list.
 *
 * This function first checks if the new environment variable is valid. If it 
 * is not valid, it prints an error message and sets the global exit status to 
 * 1. If the environment variable is valid, it tries to find it in the shell's 
 * environment list. If found, it updates the environment variable. If not 
 * found, it adds the new environment variable to the end of the list.
 *
 * @param shell The shell containing the environment list.
 * @param new_env The new environment variable to be updated or added.
 */
void	update_env(t_minishell *shell, char *new_env)
{
	t_token	*env_list;

	if (!check_valid_env(new_env))
	{
		print_error("export: not a valid identifier");
		g_exit_status = 1;
		return ;
	}
	env_list = find_env(shell, new_env);
	if (env_list)
	{
		check_free(env_list->str);
		env_list->str = ft_strdup(new_env);
	}
	else
	{
		env_list = shell->env_list;
		while (env_list->next)
			env_list = env_list->next;
		env_list->next = (t_token *)malloc(sizeof(t_token));
		env_list->next->str = ft_strdup(new_env);
		env_list->next->next = NULL;
		env_list->next->prev = env_list;
	}
}
