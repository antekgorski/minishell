/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:04:21 by sehosaf           #+#    #+#             */
/*   Updated: 2024/07/17 11:32:13 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static bool	is_number(const char *str);

/**
 * @brief The `exit` command exits the shell.
 * @param shell The shell structure.
 */
int	cmd_exit(t_shell *shell, char **args, t_connection ct)
{
	if (args[1] == NULL)
		shell->exit_status = EXIT_SUCCESS;
	else if (args[2])
	{
		ft_putendl_fd(ERR_MANY_ARGS, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (is_number(args[1]))
		shell->exit_status = (signed int)ft_atol(args[1]);
	else if (args[1] && !is_number(args[1]))
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(args[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		shell->exit_status = 255;
	}
	if (shell->exit_status < 0)
		shell->exit_status = 256 + shell->exit_status;
	if (shell->exit_status > 255)
		shell->exit_status %= 256;
	ft_putendl_fd("exit", STDERR_FILENO);
	if (ct == CON_NONE)
		cleanup_and_exit_shell(shell);
	return (shell->exit_status);
}

static bool	is_number(const char *str)
{
	if (str == NULL)
		return (false);
	while (str && *str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}
