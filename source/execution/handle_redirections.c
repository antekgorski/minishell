/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/20 06:58:52 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

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
		if (fd < 0)
		{
			perror("minishell: open");
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

void	execute_command(t_cmd *cmd, t_minishell *minishell)
{
	char	*exec_path;
	char	**envp;
	pid_t	pid;
	if (is_builtin(cmd))
	{
		// Czy w tym miejscu mam w ogóle dostęp do lexter_tab?
		// Wydaje mi się, że w parser jest odrazu czyszczone.
		e_bild(minishell->lexter_tab, minishell);
	}
	pid = fork();
	envp = list_to_envp(minishell->m_env);
	if (!envp)
	{
		perror("envp");
		exit(EXIT_FAILURE);
	}
	exec_path = find_executable(minishell->lexter_tab[0], envp);
	if (!exec_path)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(minishell->lexter_tab[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_free_split2(&envp);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (cmd->redirs)
			handle_redirections(cmd->redirs);
		if (execve(exec_path, minishell->lexter_tab, envp) == -1)
		{
			perror("execve");
			free(exec_path);
			ft_free_split2(&envp);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
		waitpid(pid, NULL, 0);
	else
	{
		perror("minishell: fork");
		exit(EXIT_FAILURE);
	}
}

void	execute_pipeline(t_cmd *cmds)
{
	int		fd[2];
	int		in_fd = 0;
	pid_t
}
