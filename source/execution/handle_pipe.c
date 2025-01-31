/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:23:56 by agorski           #+#    #+#             */
/*   Updated: 2025/01/31 08:58:46 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute_single_command(t_cmd *cmd, t_minishell *minishell)
{
	int	saved_stdin;
	int	saved_stdout;

	if (is_builtin(cmd))
	{
		saved_stdin = dup(STDIN_FILENO);
		saved_stdout = dup(STDOUT_FILENO);
		if (saved_stdin == -1 || saved_stdout == -1)
		{
			perror("dup");
			return ;
		}
		if (cmd->redirs)
			handle_redirections(cmd->redirs);
		e_bild(cmd->argv, minishell);
		if (dup2(saved_stdin, STDIN_FILENO) == -1 || dup2(saved_stdout,
				STDOUT_FILENO) == -1)
		{
			perror("dup2");
		}
		close(saved_stdin);
		close(saved_stdout);
		return ;
	}
	minishell->f_signal = execute_external(cmd->argv, minishell, cmd);
}

static void	launch_pipeline(t_cmd *cmds, t_minishell *minishell, pid_t pids[],
		int *count)
{
	int	in_fd;
	int	fd[2];

	in_fd = 0;
	while (cmds)
	{
		if (cmds->next)
		{
			pipe(fd);
			pids[*count] = run_proces(cmds, in_fd, fd[1], minishell);
			close(fd[1]);
			if (in_fd != 0)
				close(in_fd);
			in_fd = fd[0];
		}
		else
		{
			pids[*count] = run_proces(cmds, in_fd, 1, minishell);
			if (in_fd != 0)
				close(in_fd);
		}
		cmds = cmds->next;
		(*count)++;
	}
}

static void	wait_for_pipeline(pid_t pids[], int count, t_minishell *minishell)
{
	int	i;
	int	status;

	i = -1;
	while (++i < count)
	{
		waitpid(pids[i], &status, 0);
		if (WIFEXITED(status))
			minishell->f_signal = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			minishell->f_signal = 128 + WTERMSIG(status);
	}
}

static void	execute_pipeline(t_cmd *cmds, t_minishell *minishell)
{
	int		count;
	pid_t	pids[1024];

	if (check_pipeline_redirections(cmds, minishell))
		return ;
	count = 0;
	launch_pipeline(cmds, minishell, pids, &count);
	wait_for_pipeline(pids, count, minishell);
}

void	execute(t_cmd *cmds, t_minishell *minishell)
{
	t_cmd	*temp;
	int		pipeline;

	if (!cmds)
		return ;
	if (!validate_pipeline(cmds, minishell))
	{
		minishell->f_signal = 2;
		return ;
	}
	temp = cmds;
	pipeline = 0;
	while (temp->next)
	{
		pipeline = 1;
		temp = temp->next;
	}
	if (pipeline)
		execute_pipeline(cmds, minishell);
	else if (!check_redirection_access(cmds, minishell))
		execute_single_command(cmds, minishell);
}
