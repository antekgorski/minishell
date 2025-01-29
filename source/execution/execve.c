/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/29 16:08:31 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	ft_child_exec_external(t_cmd *cmd, t_minishell *minishell,
		char **args)
{
	signal_initialization_child();
	if (!cmd->argv || !cmd->argv[0])
	{
		handle_redirections(cmd->redirs);
		ft_shell_free(minishell);
		exit(0);
	}
	handle_redirections(cmd->redirs);
	minishell->f_signal = execute_child_process(args, minishell);
	ft_shell_free(minishell);
}

/**
 * @brief Function that finds the executable path of a command
 */
int	execute_external(char **args, t_minishell *minishell, t_cmd *cmd)
{
	int	pid;
	int	status;

	status = 0;
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
		ft_child_exec_external(cmd, minishell, args);
	else
	{
		signal(SIGINT, SIG_IGN);
		status = wait_for_child_process(pid);
		signal_initialization();
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (0);
}

static void	ft_child_process(t_cmd *cmd, int in_fd, int out_fd,
		t_minishell *minishell)
{
	signal_initialization_child();
	if (cmd->redirs)
		handle_redirections(cmd->redirs);
	if (in_fd != 0 && !has_input_redirection(cmd->redirs))
	{
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
	if (out_fd != 1 && !has_output_redirection(cmd->redirs))
	{
		dup2(out_fd, STDOUT_FILENO);
		close(out_fd);
	}
	if (!cmd->argv || !cmd->argv[0])
		ft_shell_free(minishell);
	else if (is_builtin(cmd))
	{
		e_bild(cmd->argv, minishell);
		ft_shell_free(minishell);
	}
	else
		minishell->f_signal = execute_child_process(cmd->argv, minishell);
	exit(0);
}

pid_t	run_proces(t_cmd *cmd, int in_fd, int out_fd, t_minishell *minishell)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
		ft_child_process(cmd, in_fd, out_fd, minishell);
	return (pid);
}
