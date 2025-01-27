/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/27 16:00:26 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

/**
 * @brief Function that finds the executable path of a command
 */
static int	count_env_variables(t_list *env)
{
	t_list	*current;
	int		count;

	count = 0;
	current = env;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

/**
 * @brief Function that finds the executable path of a command
 */
static char	**convert_env_to_envp(t_list *env, int count)
{
	t_list	*current;
	char	**envp;
	int		i;
	char	**env_vars;

	envp = malloc((count + 1) * sizeof(char *));
	if (!envp)
		return (NULL);
	current = env;
	i = 0;
	while (current)
	{
		env_vars = (char **)current->content;
		if (env_vars[1])
		{
			envp[i] = ft_strjoin(env_vars[0], "=");
			envp[i] = ft_strjoin_free(envp[i], env_vars[1]);
		}
		else
			envp[i] = ft_strdup(env_vars[0]);
		i++;
		current = current->next;
	}
	envp[i] = NULL;
	return (envp);
}

/**
 * @brief Function that finds the executable path of a command
 */
char	**list_to_envp(t_list *env)
{
	int	count;

	count = count_env_variables(env);
	return (convert_env_to_envp(env, count));
}

/**
 * @brief Function that finds the executable path of a command
 */
int	execute_child_process(char **args, t_minishell *minishell)
{
	char	*exec_path;
	char	**envp;

	envp = list_to_envp(minishell->m_env);
	if (!envp)
		ft_panic("envp", EXIT_FAILURE);
	exec_path = find_executable(args[0], envp);
	if (!exec_path)
		exec_path = handle_full_path(args[0], exec_path);
	if (!exec_path)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_free_split2(&envp);
		ft_shell_free(minishell);
		exit(127);
	}
	if (execve(exec_path, args, envp) == -1)
	{
		free(exec_path);
		ft_free_split2(&envp);
		ft_panic("execve", EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

/**
 * @brief Function that finds the executable path of a command
 */
int	wait_for_child_process(pid_t pid)
{
	int	status;

	while (1)
	{
		if (waitpid(pid, &status, WUNTRACED) == -1)
			return (EXIT_FAILURE);
		if (WIFEXITED(status) || WIFSIGNALED(status))
			break ;
	}
	return (status);
}
