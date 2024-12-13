/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:28:46 by fursini           #+#    #+#             */
/*   Updated: 2024/05/25 12:47:58 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Redirects standard input and output to the file descriptors specified 
 * in the io structure.
 *
 * @param io A pointer to a t_io_redir structure that contains the file 
 * descriptors to redirect to.
 */
void	redir(t_io_redir *io)
{
	if (!io)
		return ;
	io->stdinput = dup(STDIN_FILENO);
	if (io->stdinput == -1)
		print_error("stdinput");
	io->stdoutput = dup(STDOUT_FILENO);
	if (io->stdoutput == -1)
		print_error("stdoutput");
	if (io->fd_input != -1)
	{
		if (dup2(io->fd_input, STDIN_FILENO) == -1)
			print_error("dup2");
	}
	if (io->fd_output != -1)
	{
		if (dup2(io->fd_output, STDOUT_FILENO) == -1)
			print_error("dup2");
	}
}

/**
 * @brief Resets the standard input and output to the original file 
 * descriptors stored in the io structure.
 *
 * @param io A pointer to a t_io_redir structure that contains the 
 * original file descriptors.
 */
void	redir_reset(t_io_redir *io)
{
	if (!io)
		return ;
	if (io->stdinput != -1)
	{
		dup2(io->stdinput, STDIN_FILENO);
		close(io->stdinput);
		io->stdinput = -1;
	}
	if (io->stdoutput != -1)
	{
		dup2(io->stdoutput, STDOUT_FILENO);
		close(io->stdoutput);
		io->stdoutput = -1;
	}
}

/**
 * @brief Closes the file descriptors associated with the command's input 
 * and output redirection.
 *
 * @param cmd A pointer to a t_command structure that contains the io 
 * redirection information.
 */
void	fd_close(t_command *cmd)
{
	if (cmd && cmd->io_redir)
	{
		if (cmd->io_redir->fd_input != -1)
			close(cmd->io_redir->fd_input);
		if (cmd->io_redir->fd_output != -1)
			close(cmd->io_redir->fd_output);
	}
	close_pipe(cmd, NULL);
}
