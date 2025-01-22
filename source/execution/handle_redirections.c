/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/22 18:38:13 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"
// if builtin run in parent process return 1
// if builtin run in child process return 2
static int	is_builtin(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->argv[0], "echo"))
		return (2);
	if (!ft_strcmp(cmd->argv[0], "cd"))
		return (1);
	if (!ft_strcmp(cmd->argv[0], "pwd"))
		return (2);
	if (!ft_strcmp(cmd->argv[0], "export"))
		return (1);
	if (!ft_strcmp(cmd->argv[0], "unset"))
		return (1);
	if (!ft_strcmp(cmd->argv[0], "env"))
		return (2);
	if (!ft_strcmp(cmd->argv[0], "exit"))
		return (1);
	return (0);
}
static void	handle_redirections(t_redir *redirs)
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
		if (fd < 0)
		{
			perror("minishell: open");
			close(fd);
			exit(EXIT_FAILURE);
		}
		if (redirs->type == IREDIR)
			dup2(fd, STDIN_FILENO);
		else
			dup2(fd, STDOUT_FILENO);
		close(fd);
		redirs = redirs->next;
	}
}

static void	execute_single_command(t_cmd *cmd, t_minishell *minishell)
{
	char	*exec_path;
	char	**envp;
	pid_t	pid;

	if (is_builtin(cmd) == 1)
	{
		e_bild(cmd->argv, minishell,1);
		return ;
	}
	pid = fork();
	envp = list_to_envp(minishell->m_env);
	if (!envp)
	{
		perror("envp");
		exit(EXIT_FAILURE);
	}
	exec_path = find_executable(cmd->argv[0], envp);

	if (pid == 0)
	{
		if (!exec_path)
		{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->argv[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_free_split2(&envp);
		exit(127);
		}
		if (cmd->redirs)
			handle_redirections(cmd->redirs);
		if (is_builtin(cmd) == 2)
		{
			e_bild(cmd->argv, minishell, 0);
			exit(0);
		}
		else if (execve(exec_path, cmd->argv, envp) == -1)
		{
			perror("execve");
			free(exec_path);
			ft_free_split2(&envp);
			exit(EXIT_FAILURE);
		}

	}
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
		free(exec_path);
		free(envp);
	}
	else
	{
		perror("minishell: fork");
		exit(EXIT_FAILURE);
	}
}

static void	execute_pipeline(t_cmd *cmds, t_minishell *minishell)
{
	int		fd[2];
	int		in_fd;
	pid_t	pid;
	char	*exec_path;
	char	**envp;

	in_fd = 0;
	while (cmds)
	{
		if (cmds->next && pipe(fd) == -1)
		{
			perror("minishell: pipe");
			exit(EXIT_FAILURE);
		}
		pid = fork();
		if (pid == 0)
		{
			if (in_fd != 0)
			{
				dup2(in_fd, STDIN_FILENO);
				close(in_fd);
			}

			if (cmds->next)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
			}
			if (cmds->redirs)
				handle_redirections(cmds->redirs);
			if (is_builtin(cmds))
				e_bild(cmds->argv, minishell,0); /// Uwaga!!!
			else
			{
				envp = list_to_envp(minishell->m_env);
				if (!envp)
				{
					perror("envp");
					exit(EXIT_FAILURE);
				}
				exec_path = find_executable(cmds->argv[0], envp);
				if (!exec_path)
				{
					ft_putstr_fd("minishell: ", 2);
					ft_putstr_fd(minishell->lexter_tab[0], 2);
					ft_putstr_fd(": command not found\n", 2);
					ft_free_split2(&envp);
					exit(EXIT_FAILURE);
				}
				if (execve(exec_path, cmds->argv, envp) == -1)
				{
					perror("execve");
					free(exec_path);
					ft_free_split2(&envp);
					exit(EXIT_FAILURE);
				}
				free(exec_path); // trzeba po kminić!!!
				ft_free_split2(&envp);
			}
		}
		else if (pid > 0)
		{
			if (in_fd != 0)
				close(in_fd);
			if (cmds->next)
				close(fd[1]);
			in_fd = fd[0];
		}
		else
		{
			perror("minishell: fork");
			exit(EXIT_FAILURE);
		}
		cmds = cmds->next;
	}
	while (wait(NULL) > 0)
		;

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
