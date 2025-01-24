/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/24 16:27:12 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

// if builtin run in parent process return 1
// if builtin run in child process return 2
int	is_builtin(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->argv[0], "echo"))
		return (1);
	if (!ft_strcmp(cmd->argv[0], "cd"))
		return (1);
	if (!ft_strcmp(cmd->argv[0], "pwd"))
		return (1);
	if (!ft_strcmp(cmd->argv[0], "export"))
		return (1);
	if (!ft_strcmp(cmd->argv[0], "unset"))
		return (1);
	if (!ft_strcmp(cmd->argv[0], "env"))
		return (1);
	if (!ft_strcmp(cmd->argv[0], "exit"))
		return (1);
	return (0);
}

void	handle_redirections(t_redir *redirs)
{
	int	fd;

	while (redirs)
	{
		if (redirs->type == IREDIR)
			fd = open(redirs->filename, O_RDONLY);
		else if (redirs->type == OREDIR)
			fd = open(redirs->filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (redirs->type == APPEND)
			fd = open(redirs->filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else if (redirs->type == HERDOC)
			fd = handle_heredoc(redirs->filename);
		if (fd < 0)
		{
			perror("minishell: ");
			// ft_putstr_fd(redirs->filename, 2);
			exit(EXIT_FAILURE);
		}
		if (redirs->type == IREDIR || redirs->type == HERDOC)
			dup2(fd, STDIN_FILENO);
		else
			dup2(fd, STDOUT_FILENO);
		close(fd);
		redirs = redirs->next;
	}
}

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
	execute_external(cmd->argv, minishell, cmd);
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
			pids[*count] = launch_process(cmds, in_fd, fd[1], minishell);
			close(fd[1]);
			if (in_fd != 0)
				close(in_fd);
			in_fd = fd[0];
		}
		else
		{
			pids[*count] = launch_process(cmds, in_fd, 1, minishell);
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
	temp = cmds;
	pipeline = 0;
	while (temp->next)
	{
		pipeline = 1;
		temp = temp->next;
	}
	if (pipeline)
	{
		execute_pipeline(cmds, minishell);
	}
	else
	{
		execute_single_command(cmds, minishell);
	}
}
