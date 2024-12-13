/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:21:20 by fursini           #+#    #+#             */
/*   Updated: 2024/05/25 12:54:01 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Initialize the pipe for the shell command.
 *
 * This function initializes the pipe for the shell command. It iterates over 
 * the commands and if the command has a pipe or the previous command has a 
 * pipe, it allocates memory for the pipe file descriptor and creates the pipe.
 *
 * @param shell The shell structure containing the command.
 */
void	init_pipe(t_minishell *shell)
{
	t_command	*cmd;

	cmd = shell->command;
	while (cmd)
	{
		if (cmd->pipe || (cmd->prev && cmd->prev->pipe))
		{
			cmd->fd_pipe = (int *)malloc(sizeof(cmd->fd_pipe) * 2);
			if (!cmd->fd_pipe || pipe(cmd->fd_pipe) != 0)
				return ;
		}
		cmd = cmd->next;
	}
}

/**
 * @brief Duplicate the file descriptors for the command pipe.
 *
 * This function duplicates the file descriptors for the command pipe. 
 * If the previous command has a pipe, it duplicates its read end to the 
 * standard input. If the command has a pipe,
 * it duplicates its write end to the standard output.
 *
 * @param cmd The command structure.
 */
static void	pipe_dup2(t_command *cmd)
{
	if (!cmd)
		return ;
	if (cmd->prev && cmd->prev->pipe)
		dup2(cmd->prev->fd_pipe[0], STDIN_FILENO);
	if (cmd->pipe)
		dup2(cmd->fd_pipe[1], STDOUT_FILENO);
}

/**
 * @brief Setup the pipe for the command.
 *
 * This function sets up the pipe for the command. It duplicates the file 
 * descriptors, closes the pipe, redirects the IO and closes the file 
 * descriptor.
 *
 * @param cmd The command structure.
 * @param shell The shell structure containing the command.
 */
void	setup_pipe(t_command *cmd, t_minishell *shell)
{
	pipe_dup2(cmd);
	close_pipe(shell->command, cmd);
	redir(cmd->io_redir);
	fd_close(cmd);
}

/**
 * @brief Close the pipe for the commands.
 *
 * This function closes the pipe for the commands. It iterates over the 
 * commands and if the command is not the current command and it has a pipe, 
 * it closes both ends of the pipe.
 *
 * @param cmds The commands structure.
 * @param cmd The current command structure.
 */
void	close_pipe(t_command *cmds, t_command *cmd)
{
	t_command	*tmp;

	tmp = cmds;
	if (!cmds)
		return ;
	while (tmp)
	{
		if (tmp != cmd && tmp->fd_pipe)
		{
			close(tmp->fd_pipe[0]);
			close(tmp->fd_pipe[1]);
		}
		tmp = tmp->next;
	}
}
