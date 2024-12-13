/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_proc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:29:30 by sehosaf           #+#    #+#             */
/*   Updated: 2024/08/01 18:39:44 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "signals.h"

extern int	g_pids[MAX_CMD];

/**
 * @brief Creates a child process to execute the command
 * @param shell The shell structure
 * @param p The pipeline of the command
 * @param cur The current command in the pipeline to execute
 * @return Process ID of the child process
 */
pid_t	create_child(t_shell *shell, t_pipeline *p, t_pipeline *cur)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror(ERR_FORK);
		return (EXIT_FAILURE);
	}
	if (pid == 0)
		exit(exec_command(shell, p, cur, pid));
	return (pid);
}

/**
 * @brief Executes the pipeline of commands in async mode
 * @param shell The shell structure
 * @param cmds The array of process IDs
 * @param num_cmds The number of commands in the pipeline
 */
void	exec_pipeline(t_shell *shell, int num_cmds)
{
	int	i;
	int	status;

	i = 0;
	while (i < num_cmds)
	{
		waitpid(g_pids[i], &(status), WUNTRACED);
		if (WEXITSTATUS(status))
			shell->exit_status = WEXITSTATUS(status);
		if (WIFSIGNALED(status))
			shell->exit_status = WTERMSIG(status);
		i++;
	}
}

/**
 * @brief Executes the pipeline of commands in sync mode
 * @param shell The shell structure
 * @param pid The process ID of the child process
 */
void	wait_for_child_process(t_shell *shell, pid_t pid)
{
	int	status;

	waitpid(pid, &status, WUNTRACED);
	while (!WIFEXITED(status) && !WIFSIGNALED(status))
		waitpid(pid, &status, WUNTRACED);
	if (WEXITSTATUS(status))
		shell->exit_status = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
		shell->exit_status = WTERMSIG(status);
}

/**
 * @brief Checks if the pipeline is asynchronous
 * @param pipeline The pipeline of commands
 * @return true if the pipeline is asynchronous, false otherwise
 */
bool	is_async(t_pipeline *pipeline)
{
	t_pipeline	*current;

	current = pipeline;
	while (current)
	{
		if (current->cmd.conn_type == CON_OR
			|| current->cmd.conn_type == CON_AND)
			return (false);
		current = current->next;
	}
	return (true);
}
