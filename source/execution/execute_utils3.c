/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/30 12:38:35 by prutkows         ###   ########.fr       */
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

	if (!exec_path || !*exec_path)
		return ;
	if (stat(exec_path, &buf) == 0 && S_ISDIR(buf.st_mode))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(exec_path, 2);
		ft_putstr_fd(": Is a directory\n", 2);
		free(exec_path);
		ft_free_split2(&envp);
		ft_shell_free(minishell);
		exit(126);
	}
}

void	handle_execve_error(char *exec_path, char **envp)
{
	free(exec_path);
	ft_free_split2(&envp);
	ft_panic("execve", EXIT_FAILURE);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*static_str;
	char		*token;

	if (str)
		static_str = str;
	if (!static_str)
		return (NULL);
	while (*static_str && ft_strchr(delim, *static_str))
		static_str++;
	if (!*static_str)
		return (NULL);
	token = static_str;
	while (*static_str && !ft_strchr(delim, *static_str))
		static_str++;
	if (*static_str)
	{
		*static_str = '\0';
		static_str++;
	}
	return (token);
}
