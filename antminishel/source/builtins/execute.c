/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2024/12/19 16:05:29 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

// builtins functions
int	execute_command(char **args, t_minishell *minishell)
{
    if (!args || !args[0])
        return (1);
    if (args[0] && ft_strcmp(args[0], "pwd") == 0)
        return (ft_pwd());
    else if (args[0] && ft_strcmp(args[0], "echo") == 0)
        return (ft_echo(args));
    else if (args[0] && ft_strcmp(args[0], "cd") == 0)
        return (ft_cd(args));
    else if (args[0] && ft_strcmp(args[0], "exit") == 0)
        return (ft_exit());
    else if (args[0] && ft_strcmp(args[0], "env") == 0)
        return (ft_env(minishell));
    else
        return (1);
    return (1);
}
{
	if (!args || !args[0])
		return (1);
	if (args[0] && ft_strcmp(args[0], "pwd") == 0)
		return (ft_pwd());
	else if (args[0] && ft_strcmp(args[0], "echo") == 0)
		return (ft_echo(args));
	else if (args[0] && ft_strcmp(args[0], "cd") == 0)
		return (ft_cd(args));
	else if (args[0] && ft_strcmp(args[0], "exit") == 0)
		return (ft_exit());
	else if (args[0] && ft_strcmp(args[0], "env") == 0)
		return (ft_env());
	else
		return (1);
	return (1);
}
