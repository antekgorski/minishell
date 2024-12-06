/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:04:06 by sehosaf           #+#    #+#             */
/*   Updated: 2024/07/30 21:51:44 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static pid_t	find_exec_type(t_shell *shell, t_pipeline *p, t_pipeline *cur);
static pid_t	absolute_path(t_shell *shell, t_pipeline *p, t_pipeline *cur);
static pid_t	relative_path(t_shell *shell, t_pipeline *p, t_pipeline *cur);
static pid_t	handle_builtin(t_shell *shell, t_pipeline *p, t_pipeline *cur);

pid_t	g_pids[MAX_CMD];

/**
 * @brief Executes the commands in the pipeline and returns the exit status
 * @param pipeline The pipeline to execute
 * @param shell The shell structure
 * @return EXIT_SUCCESS or EXIT_FAILURE
 * @note This function is the entry point for executing a pipeline
 */
void	execute(t_pipeline *pipeline, t_shell *shell)
{
	t_pipeline	*cur;
	int			i;
	bool		async;

	cur = pipeline;
	i = 0;
	if (create_pipes(pipeline) == EXIT_FAILURE)
		return ;
	async = is_async(pipeline);
	while (cur != NULL)
	{
		if (!async
			&& !should_execute(cur->cmd.conn_type, shell->exit_status))
			break ;
		g_pids[i] = find_exec_type(shell, pipeline, cur);
		if (!async)
			wait_for_child_process(shell, g_pids[i]);
		i++;
		cur = cur->next;
	}
	close_pipes(pipeline);
	if (async)
		exec_pipeline(shell, i);
}

static pid_t	find_exec_type(t_shell *shell, t_pipeline *p, t_pipeline *cur)
{
	if (is_builtin(cur->cmd))
		return (handle_builtin(shell, p, cur));
	else if (cur->cmd.args[0][0] == '/')
		return (absolute_path(shell, p, cur));
	else
		return (relative_path(shell, p, cur));
}

static pid_t	handle_builtin(t_shell *shell, t_pipeline *p, t_pipeline *cur)
{
	if (cur->next == NULL && cur->prev == NULL
		&& (cur->cmd.infile == NULL && cur->cmd.outfile == NULL))
		return (execute_builtin(cur->cmd, shell));
	else
		return (create_child(shell, p, cur));
}

static pid_t	absolute_path(t_shell *shell, t_pipeline *p, t_pipeline *cur)
{
	struct stat	st;

	if (stat(cur->cmd.args[0], &st) == -1)
	{
		perror(ERR_GENERIC);
		shell->exit_status = 127;
		return (EXIT_FAILURE);
	}
	if (S_ISDIR(st.st_mode))
	{
		ft_putendl_fd(ERR_IS_DIR, 2);
		shell->exit_status = 126;
		return (EXIT_FAILURE);
	}
	return (create_child(shell, p, cur));
}

static pid_t	relative_path(t_shell *shell, t_pipeline *p, t_pipeline *cur)
{
	char	*cmd_path;

	cmd_path = find_sys_cmd(cur->cmd.args[0], shell->env);
	if (cmd_path == NULL)
	{
		shell->exit_status = 127;
		return (EXIT_FAILURE);
	}
	free(cur->cmd.args[0]);
	cur->cmd.args[0] = cmd_path;
	return (create_child(shell, p, cur));
}
