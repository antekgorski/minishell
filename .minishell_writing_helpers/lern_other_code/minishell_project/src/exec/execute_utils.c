/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:25:20 by sehosaf           #+#    #+#             */
/*   Updated: 2024/07/17 12:44:41 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	concat_key_value(char **env_str, t_env *env);
static char	*check_file(char *file);

/**
 * @brief Convert the environment variables to an array
 * @param env The structure of environment variables
 * @note The array must be freed after use
 * @return The array of environment variables in the format "key=value"
 */
char	**env_list_to_array(t_env *env)
{
	int		count;
	char	**env_array;
	t_env	*e;
	int		i;

	e = env;
	count = get_env_size(env);
	env_array = malloc((count + 1) * sizeof(char *));
	if (env_array == NULL)
		return (NULL);
	i = 0;
	while (e != NULL)
	{
		env_array[i] = malloc(strlen(e->key) + strlen(e->value) + 2);
		if (env_array[i] == NULL)
			return (free_split(env_array), NULL);
		concat_key_value(&env_array[i], e);
		if (env_array[i] == NULL)
			return (free_split(env_array), NULL);
		i++;
		e = e->next;
	}
	env_array[i] = NULL;
	return (env_array);
}

/**
 * @brief Find the path of a system command
 * @param cmd The command to find
 * @param env The environment variables
 * @note The path must be freed after use
 * @return The path of the command if found, NULL otherwise
 */
char	*find_sys_cmd(char *cmd, t_env *env)
{
	char	*path;
	char	**path_dirs;
	char	sys_cmd_path[PATH_MAX];
	int		i;

	path = get_env_val(env, "PATH");
	path_dirs = ft_split(path, ':');
	if (path_dirs == NULL)
		return (NULL);
	i = -1;
	while (path_dirs[++i] != NULL)
	{
		if (strlen(path_dirs[i]) + strlen(cmd) + 1 < PATH_MAX)
		{
			ft_memset(sys_cmd_path, 0, PATH_MAX);
			ft_strlcpy(sys_cmd_path, path_dirs[i], PATH_MAX);
			ft_strlcat(sys_cmd_path, "/", PATH_MAX);
			ft_strlcat(sys_cmd_path, cmd, PATH_MAX);
			if (access(sys_cmd_path, F_OK) == 0)
				return (free_split(path_dirs), check_file(sys_cmd_path));
		}
	}
	free_split(path_dirs);
	printf("%s%s: not found\n", ERR_GENERIC, cmd);
	return (NULL);
}

static void	concat_key_value(char **env_str, t_env *env)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(env->key) + ft_strlen(env->value) + 2;
	tmp = ft_calloc(len, sizeof(char));
	if (tmp == NULL)
	{
		*env_str = NULL;
		return ;
	}
	ft_strlcat(tmp, env->key, len);
	ft_strlcat(tmp, "=", len);
	ft_strlcat(tmp, env->value, len);
	*env_str = tmp;
}

/**
 * @note Returns only if the file exists and is executable
 */
static char	*check_file(char *file)
{
	if (access(file, F_OK) == 0)
	{
		if (access(file, X_OK) == 0)
			return (ft_strdup(file));
		else
			printf("%s%d: %s: %s\n", ERR_GENERIC, errno, file, ERR_PERM);
	}
	return (NULL);
}

/**
 * @brief Check if a command should be executed based on the connection type
 * and the last exit status
 * @param conn_type The type of connection between the commands
 * @param exit_status The exit status of the last command
 * @return true is the command should be executed, false otherwise
 */
bool	should_execute(t_connection conn_type, int exit_status)
{
	if (conn_type == CON_AND && exit_status != EXIT_SUCCESS)
		return (false);
	if (conn_type == CON_OR && exit_status != EXIT_SUCCESS)
		return (true);
	return (true);
}
