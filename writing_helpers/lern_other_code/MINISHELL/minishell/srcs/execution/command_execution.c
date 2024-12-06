/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:16:45 by fursini           #+#    #+#             */
/*   Updated: 2024/05/25 13:55:28 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path(char *cmd, char **envp)
{
	char		*path;
	char		**split;
	int			i;

	i = 0;
	path = NULL;
	if (ft_strchr(cmd, '/'))
		return (cmd);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	split = ft_split(envp[i] + 5, ':');
	i = -1;
	while (split[++i])
	{
		path = join_str(split[i], "/", cmd);
		if (access(path, F_OK) == 0)
		{
			free_matrix(split);
			return (path);
		}
	}
	free_matrix(split);
	return (NULL);
}
