/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/24 21:08:47 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

/**
 * @brief Function that finds the executable path of a command
 */
int	execute_external(char **args, t_minishell *minishell, t_cmd *cmd)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
	{
		if (!cmd->argv || !cmd->argv[0])
		{
			handle_redirections(cmd->redirs);
			exit(0);
		}
		handle_redirections(cmd->redirs);
		execute_child_process(args, minishell);
	}
	else
		status = wait_for_child_process(pid);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (0);
}

pid_t	launch_process(t_cmd *cmd, int in_fd, int out_fd,
		t_minishell *minishell)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		if (!cmd->argv || !cmd->argv[0])
		{
			handle_redirections(cmd->redirs);
			exit(0);
		}
		if (in_fd != 0)
		{
			dup2(in_fd, STDIN_FILENO);
			close(in_fd);
		}
		if (out_fd != 1)
		{
			dup2(out_fd, STDOUT_FILENO);
			close(out_fd);
		}
		handle_redirections(cmd->redirs);
		if (is_builtin(cmd))
			e_bild(cmd->argv, minishell);
		else
		minishell->f_signal = execute_child_process(cmd->argv, minishell);
		exit(minishell->f_signal);
	}
	return (pid);
}
