/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:59:32 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/05/25 12:02:07 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Checks if the given command is a built-in command.
 *
 * @param cmd The command to be checked.
 * @return true if the command is a built-in command, false otherwise.
 */
bool	is_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "echo"))
		return (true);
	if (!ft_strcmp(cmd, "cd"))
		return (true);
	if (!ft_strcmp(cmd, "pwd"))
		return (true);
	if (!ft_strcmp(cmd, "export"))
		return (true);
	if (!ft_strcmp(cmd, "unset"))
		return (true);
	if (!ft_strcmp(cmd, "env"))
		return (true);
	if (!ft_strcmp(cmd, "exit"))
		return (true);
	return (false);
}

/**
 * @brief Executes a built-in command.
 *
 * This function executes a built-in command. It checks the name of the command
 * and calls the corresponding function to execute it.
 * The global exit status is updated based on the result of the command 
 * execution.
 *
 * @param shell The shell in which the command is to be executed.
 * @param cmd The command to be executed.
 * @return Always returns 1.
 */
int	execute_builtin(t_minishell *shell, t_command *cmd)
{
	if (ft_strcmp(cmd->name, "echo") == 0)
		g_exit_status = echo(cmd);
	else if (ft_strcmp(cmd->name, "cd") == 0)
		g_exit_status = cd(cmd, shell);
	else if (ft_strcmp(cmd->name, "pwd") == 0)
		g_exit_status = pwd();
	else if (ft_strcmp(cmd->name, "export") == 0)
		export(shell, cmd);
	else if (ft_strcmp(cmd->name, "unset") == 0)
		g_exit_status = unset(shell, cmd);
	else if (ft_strcmp(cmd->name, "env") == 0)
		g_exit_status = env(shell);
	else if (ft_strcmp(cmd->name, "exit") == 0)
		exit_minishell(shell, cmd);
	return (1);
}
