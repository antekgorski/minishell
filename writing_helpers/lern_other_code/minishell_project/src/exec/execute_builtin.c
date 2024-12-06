/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:22:48 by sehosaf           #+#    #+#             */
/*   Updated: 2024/06/24 21:48:41 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

/**
 * @brief Check if the command is a builtin command
 * @param command The command to check
 * @return true if the command is a builtin command, false otherwise
 */
bool	is_builtin(t_command command)
{
	char		*cmd_name;
	int			i;
	const char	*builtin_commands[] = {"cd", "echo", "env", "exit", "export",
		"pwd", "unset", NULL};

	i = 0;
	cmd_name = command.args[0];
	while (builtin_commands[i])
	{
		if (ft_strcmp(cmd_name, builtin_commands[i]) == 0)
			return (true);
		i++;
	}
	return (false);
}

/**
 * @brief Execute a builtin command
 * @param command The command to execute
 * @param shell The shell structure
 */
int	execute_builtin(t_command command, t_shell *shell)
{
	char			*cmd_name;
	int				ret;
	t_connection	connection_type;

	ret = EXIT_SUCCESS;
	connection_type = command.conn_type;
	cmd_name = command.args[0];
	if (ft_strcmp(cmd_name, "cd") == 0)
		ret = cmd_cd(shell, command.args);
	else if (ft_strcmp(cmd_name, "echo") == 0)
		ret = cmd_echo((const char **)command.args);
	else if (ft_strcmp(cmd_name, "env") == 0)
		ret = cmd_env(shell);
	else if (ft_strcmp(cmd_name, "exit") == 0)
		ret = cmd_exit(shell, command.args, connection_type);
	else if (ft_strcmp(cmd_name, "export") == 0)
		ret = cmd_export(shell, command.args[1]);
	else if (ft_strcmp(cmd_name, "pwd") == 0)
		ret = cmd_pwd();
	else if (ft_strcmp(cmd_name, "unset") == 0)
		ret = cmd_unset(shell, command.args[1]);
	return (ret);
}
