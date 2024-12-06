/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:27:38 by fursini           #+#    #+#             */
/*   Updated: 2024/05/25 12:35:31 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Waits for child processes to finish and returns their exit status.
 *
 * @return int The exit status of the child processes.
 */
static int	wait_child(void)
{
	pid_t	wpid;
	int		status;

	wpid = 0;
	status = 0;
	while (wpid != -1)
		wpid = waitpid(-1, &status, 0);
	if (WIFSIGNALED(status))
		return ((int)(128 + WTERMSIG(status)));
	else if (WIFEXITED(status))
		return ((int)WEXITSTATUS(status));
	else
		return (status);
}

/**
 * @brief Executes a command in a child process.
 *
 * @param shell The current shell state.
 * @param cmd The command to execute.
 */
static void	execute_child(t_minishell *shell, t_command *cmd)
{
	if (!cmd || !cmd->name || check_file(cmd->io_redir))
		free_minishell(shell);
	setup_pipe(cmd, shell);
	free_matrix(shell->envp);
	shell->envp = create_env(shell->env_list);
	if (is_path(cmd->name, shell) && !is_folder(cmd->name, shell))
		execve(cmd->name, cmd->args, shell->envp);
	else if (!is_builtin(cmd->name))
		execve(get_path(cmd->name, shell->envp), cmd->args, shell->envp);
	else if (is_builtin(cmd->name) && execute_builtin(shell, cmd))
		free_minishell(shell);
	ft_putstr_fd(cmd->name, 2);
	ft_putstr_fd(": command not found\n", 2);
	g_exit_status = 127;
	free_minishell(shell);
}

/**
 * @brief Executes a sequence of commands.
 *
 * @param shell The current shell state.
 */
static void	execute_commands(t_minishell *shell)
{
	t_command	*cmd;
	pid_t		pid;

	pid = -1;
	cmd = shell->command;
	init_pipe(shell);
	while (pid != 0 && cmd)
	{
		pid = fork();
		if (pid == -1)
			print_error("fork error");
		else if (pid == 0)
			execute_child(shell, cmd);
		cmd = cmd->next;
	}
	fd_close(shell->command);
	g_exit_status = wait_child();
}

/**
 * @brief Executes a command or sequence of commands.
 *
 * @param shell The current shell state.
 */
void	execute(t_minishell *shell)
{
	t_command	*cmd;

	cmd = shell->command;
	if (cmd && cmd->name && !cmd->next && is_builtin(cmd->name))
	{
		redir(cmd->io_redir);
		fd_close(cmd);
		execute_builtin(shell, cmd);
		redir_reset(shell->command->io_redir);
	}
	else
		execute_commands(shell);
}
