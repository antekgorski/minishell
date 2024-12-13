/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:28:19 by sehosaf           #+#    #+#             */
/*   Updated: 2024/07/17 14:18:33 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	handle_input(t_command *cmd);
static void	handle_output(t_command *cmd);
static void	handle_pipe(t_pipeline *current);
static void	handle_heredoc(t_command *cmd, pid_t pid);

/**
 * @brief Execute a command
 * @param shell The shell structure
 * @param p The pipeline structure
 * @param cur The current command to execute
 * @note This function executes the command in a child process
 */
int	exec_command(t_shell *shell, t_pipeline *p, t_pipeline *cur, pid_t pid)
{
	char	**env_array;

	handle_heredoc(&cur->cmd, pid);
	handle_input(&cur->cmd);
	handle_output(&cur->cmd);
	handle_pipe(cur);
	close_pipes(p);
	if (is_builtin(cur->cmd))
		return (execute_builtin(cur->cmd, shell));
	env_array = env_list_to_array(shell->env);
	if (env_array == NULL)
	{
		ft_putendl_fd(ERR_ENV, 2);
		return (EXIT_FAILURE);
	}
	if (execve(cur->cmd.args[0], cur->cmd.args, env_array) == -1)
	{
		free_split(env_array);
		return (perror(ERR_EXEC), EXIT_FAILURE);
	}
	free_split(env_array);
	return (EXIT_SUCCESS);
}

/**
 * @note If the command has an input file, redirect the input of the command
 * to the input file
 */
static void	handle_input(t_command *cmd)
{
	int	in;

	if (cmd->infile != NULL)
	{
		in = open(cmd->infile, O_RDONLY);
		if (in < 0)
		{
			perror(ERR_INPUT_FILE);
			exit(EXIT_FAILURE);
		}
		if (dup2(in, STDIN_FILENO) < 0)
		{
			perror(ERR_INPUT_FILE);
			close(in);
			exit(EXIT_FAILURE);
		}
		close(in);
	}
}

/**
 * @note If the command has an output file, redirect the output of the command
 * to the output file
 * @note If the output file is in append mode, open the file in append mode
 */
static void	handle_output(t_command *cmd)
{
	int	out;

	if (cmd->outfile != NULL)
	{
		if (cmd->ap_mode)
			out = open(cmd->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			out = open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (out < 0)
		{
			perror(ERR_OUTPUT_FILE);
			exit(EXIT_FAILURE);
		}
		if (dup2(out, STDOUT_FILENO) < 0)
		{
			perror(ERR_OUTPUT_FILE);
			close(out);
			exit(EXIT_FAILURE);
		}
		close(out);
	}
}

static void	handle_pipe(t_pipeline *current)
{
	if (current->prev == NULL && current->next != NULL)
		dup2(current->fd_out, STDOUT_FILENO);
	if (current->prev != NULL && current->next != NULL)
	{
		dup2(current->prev->fd_in, STDIN_FILENO);
		dup2(current->fd_out, STDOUT_FILENO);
	}
	if (current->next == NULL && current->prev != NULL)
		dup2(current->prev->fd_in, STDIN_FILENO);
}

static void	handle_heredoc(t_command *cmd, pid_t pid)
{
	int		fd;
	char	*line;

	if (cmd->is_heredoc)
	{
		if (cmd->infile != NULL)
			free(cmd->infile);
		cmd->infile = ft_strjoin("/tmp/heredoc_pid.", ft_itoa(pid));
		fd = open(cmd->infile, O_RDWR | O_CREAT | O_TRUNC, 0600);
		if (fd == -1)
		{
			perror("minishell: open ");
			exit(EXIT_FAILURE);
		}
		line = readline("heredoc> ");
		while (line != NULL)
		{
			if (ft_strcmp(line, cmd->limiter) == 0)
				break ;
			ft_putendl_fd(line, fd);
			free(line);
			line = readline("heredoc> ");
		}
		close(fd);
	}
}
