/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:56:18 by fursini           #+#    #+#             */
/*   Updated: 2024/05/25 10:13:41 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Create an environment array from a linked list of tokens.
 *
 * This function traverses a linked list of tokens, where each token represents 
 * an environment variable. It creates an array of strings where each string 
 * is a copy of the token's string. The array is null-terminated.
 *
 * @param env_list A pointer to the first element of a linked list of tokens 
 * representing environment variables.
 * @return char** A pointer to the first element of an array of strings, each 
 * representing an environment variable.
 */
char	**create_env(t_token *env_list)
{
	char	**env;
	t_token	*tmp;
	int		i;

	i = 0;
	tmp = env_list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	tmp = env_list;
	while (tmp)
	{
		env[i] = ft_strdup(tmp->str);
		i++;
		tmp = tmp->next;
	}
	env[i] = NULL;
	return (env);
}

/**
 * @brief Sorts an array of environment variables.
 *
 * This function sorts an array of strings, where each string represents 
 * an environment variable.
 * The sorting is done in-place using the bubble sort algorithm.
 *
 * @param env A pointer to the first element of an array of strings 
 * representing environment variables.
 */
static void	sort_env(char **env)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		j = i + 1;
		while (env[j])
		{
			if (ft_strcmp(env[i], env[j]) > 0)
			{
				tmp = env[i];
				env[i] = env[j];
				env[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

/**
 * @brief Prints the environment variables.
 *
 * This function creates an array of strings from the shell's environment 
 * variables, sorts it, and then prints each variable in the format 
 * "declare -x key=value".
 *
 * @param shell A pointer to the shell instance where the environment variables 
 * are stored.
 */
static void	print_export(t_minishell *shell)
{
	char	**env;
	char	*key;
	int		i;

	i = 0;
	env = create_env(shell->env_list);
	sort_env(env);
	while (env[i])
	{
		key = get_key_value(env[i]);
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(key, 1);
		if (ft_strchr(env[i], '='))
		{
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(env[i] + ft_strlen(key) + 1, 1);
			ft_putstr_fd("\"", 1);
		}
		ft_putstr_fd("\n", 1);
		check_free(key);
		i++;
	}
	free_matrix(env);
}

/**
 * @brief Handles the 'export' shell command.
 *
 * This function is responsible for handling the 'export' shell command. 
 * If the command has no arguments, it prints all environment variables. 
 * If there are arguments, it updates the environment variables with
 * the provided arguments.
 *
 * @param shell A pointer to the shell instance where the environment variables 
 * are stored.
 * @param cmd A pointer to the command structure containing the arguments for 
 * the export command.
 */
void	export(t_minishell *shell, t_command *cmd)
{
	int		i;

	i = 1;
	g_exit_status = 0;
	if (!cmd->args[1])
		print_export(shell);
	else
	{
		while (cmd->args[i])
		{
			update_env(shell, cmd->args[i]);
			i++;
		}
	}
}
