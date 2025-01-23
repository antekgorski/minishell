/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/23 12:47:56 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

/**
 * @brief function to join two strings and free the first one
 */
char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*joined_str;

	if (!s1 || !s2)
		return (NULL);
	joined_str = ft_strjoin(s1, s2);
	if (!joined_str)
		return (NULL);
	free(s1);
	return (joined_str);
}

/**
 * @brief function to get the PATH variable from the environment
 */
static char	*get_path_variable(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (ft_strdup(*envp + 5));
		envp++;
	}
	return (NULL);
}

/**
 * @brief function to construct the full path to the executable
 */
static char	*construct_full_path(const char *token, const char *command)
{
	char	*full_path;
	size_t	len;

	len = ft_strlen(token) + ft_strlen(command) + 2;
	full_path = (char *)malloc(len);
	if (!full_path)
		return (NULL);
	ft_strlcpy(full_path, (char *)token, len);
	ft_strlcat(full_path, "/", len);
	ft_strlcat(full_path, command, len);
	return (full_path);
}

/**
 * @brief function to find the executable in the PATH
 */
char	*find_executable(char *command, char **envp)
{
	char	*path;
	char	*token;
	char	*full_path;

	path = get_path_variable(envp);
	token = strtok(path, ":");
	while (token)
	{
		full_path = construct_full_path(token, command);
		if (!full_path)
		{
			free(path);
			return (NULL);
		}
		if (access(full_path, X_OK) == 0)
		{
			free(path);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}

/**
 * @brief function to free a split string
 */
void	ft_free_split2(char ***split)
{
	int	i;

	if (!split || !*split)
		return ;
	i = 0;
	while ((*split)[i])
	{
		free((*split)[i]);
		(*split)[i] = NULL;
		i++;
	}
	free(*split);
	*split = NULL;
}
