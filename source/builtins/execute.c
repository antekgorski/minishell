/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/13 12:40:11 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

// builtins functions
int	e_bild(char **args, t_minishell *minishell)
{
	if (!args || !args[0])
		return (1);
	if (args[0] && ft_strcmp(args[0], "pwd") == 0)
		minishell->f_signal = ft_pwd();
	else if (args[0] && ft_strcmp(args[0], "echo") == 0)
		minishell->f_signal = ft_echo(args);
	else if (args[0] && ft_strcmp(args[0], "cd") == 0)
		minishell->f_signal = ft_cd(args, minishell);
	else if (args[0] && ft_strcmp(args[0], "exit") == 0)
		minishell->f_signal = ft_exit(minishell);
	else if (args[0] && ft_strcmp(args[0], "env") == 0)
		minishell->f_signal = ft_env(minishell);
	else if (args[1] && ft_strcmp(args[0], "unset") == 0)
		minishell->f_signal = ft_unset(minishell, &args[1]);
	else if (ft_strcmp(args[0], "export") == 0)
		minishell->f_signal = ft_export(minishell, args);
	else
	{
		minishell->f_signal = execute_external(args, minishell);
		// return (0);
	}
	return (minishell->f_signal);
}
