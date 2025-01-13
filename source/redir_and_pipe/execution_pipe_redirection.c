/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_pipe_redirection.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:08:14 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/13 12:40:26 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	execute_commands(t_cmd *cmd_list, t_minishell *minishell)
{
	int fd_in = STDIN_FILENO;
	int fd[2];
	pid_t pid;
	t_cmd *cmd = cmd_list;

	while (cmd)
	{
		if (cmd->next)
		{
			if (pipe(fd) == -1)
				ft_panic("pipe failed", 1);
		}

		pid = fork();
		if (pid == 0)
		{
			// Child process
			if (cmd->infile)
			{
				fd_in = open(cmd->infile, O_RDONLY);
				if (fd_in < 0)
				{
					perror("open infile");
					exit(EXIT_FAILURE);
				}
				dup2(fd_in, STDIN_FILENO);
				close(fd_in);
			}
			else if (fd_in != STDIN_FILENO)
			{
				dup2(fd_in, STDIN_FILENO);
				close(fd_in);
			}

			if (cmd->outfile)
			{
				int flags = O_WRONLY | O_CREAT;
				if (cmd->append)
					flags |= O_APPEND;
				else
					flags |= O_TRUNC;
				int fd_out = open(cmd->outfile, flags, 0644);
				if (fd_out < 0)
				{
					perror("open outfile");
					exit(EXIT_FAILURE);
				}
				dup2(fd_out, STDOUT_FILENO);
				close(fd_out);
			}
			else if (cmd->next)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
			}

			if (cmd->next)
				close(fd[0]);
			// Być może da się to usprawnić !?!?!?
			int builtin_status = e_bild(cmd->cmd, minishell);
			if (builtin_status == 0)
				execute_external(cmd->cmd, minishell);
			else
				exit(builtin_status);
			exit(minishell->f_signal);
		}
		else if (pid < 0)
			ft_panic("fork failed", 1);
		else
		{
			// Parent ptocess
			waitpid(pid, &minishell->f_signal, 0);
			if (fd_in != STDIN_FILENO)
				close(fd_in);
			if (cmd->next)
			{
				close(fd[1]);
				fd_in = fd[0];
			}
		}
		cmd = cmd->next;
	}
}