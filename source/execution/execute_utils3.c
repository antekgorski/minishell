/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/28 13:37:51 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char	*handle_full_path(char *command, char *exec_path)
{
	char	*new_exec_path;

	if (ft_strchr(command, '/'))
	{
		if (access(command, X_OK) == 0)
		{
			new_exec_path = ft_strdup(command);
			free(exec_path);
			return (new_exec_path);
		}
	}
	return (exec_path);
}

char	*get_executable_path(char *arg, char **envp)
{
	char	*exec_path;

	exec_path = find_executable(arg, envp);
	if (!exec_path)
		exec_path = handle_full_path(arg, exec_path);
	return (exec_path);
}

void	check_path_is_dir(char *exec_path, char **envp, t_minishell *minishell)
{
	struct stat	buf;

	if (stat(exec_path, &buf) == 0)
	{
		if (S_ISDIR(buf.st_mode))
		{
			ft_putstr_fd("bash: ", 2);
			ft_putstr_fd(exec_path, 2);
			ft_putstr_fd(": Is a directory\n", 2);
			free(exec_path);
			ft_free_split2(&envp);
			ft_shell_free(minishell);
			exit(126);
		}
	}
}

void	handle_execve_error(char *exec_path, char **envp)
{
	free(exec_path);
	ft_free_split2(&envp);
	ft_panic("execve", EXIT_FAILURE);
}
