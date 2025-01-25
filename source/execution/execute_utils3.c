/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/25 19:20:54 by prutkows         ###   ########.fr       */
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
