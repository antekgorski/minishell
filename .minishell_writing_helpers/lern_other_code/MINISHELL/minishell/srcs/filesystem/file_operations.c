/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:07:14 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/05/25 13:03:55 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Checks if the file descriptor for input/output is valid.
 *
 * @param io A pointer to the t_io_redir structure.
 * @return true if the file descriptor for input or output is -1.
 * @return false otherwise.
 */
bool	check_file(t_io_redir *io)
{
	if (!io || (!io->input && !io->output))
		return (false);
	if ((io->input && io->fd_input == -1)
		|| (io->output && io->fd_output == -1))
		return (true);
	return (false);
}

/**
 * @brief Checks if the command is a path.
 *
 * @param cmd The command to check.
 * @param shell A pointer to the t_minishell structure.
 * @return true if the command is a path.
 * @return false otherwise.
 */
bool	is_path(char *cmd, t_minishell *shell)
{
	if (!cmd)
		return (false);
	if (ft_strchr(cmd, '/') != NULL)
	{
		if (access(cmd, F_OK) != 0)
		{
			print_error("No such file or directory");
			g_exit_status = 127;
			free_minishell(shell);
		}
		else if (access(cmd, X_OK) != 0)
		{
			print_error("Permission denied");
			g_exit_status = 126;
			free_minishell(shell);
		}
		return (true);
	}
	return (false);
}

/**
 * @brief Checks if the command is a directory.
 *
 * @param cmd The command to check.
 * @param shell A pointer to the t_minishell structure.
 * @return false in all cases.
 */
bool	is_folder(char *cmd, t_minishell *shell)
{
	struct stat	buf;

	if (stat(cmd, &buf) == -1)
		return (false);
	if (S_ISDIR(buf.st_mode))
	{
		g_exit_status = 126;
		print_error("Is a directory");
		free_minishell(shell);
	}
	return (false);
}
