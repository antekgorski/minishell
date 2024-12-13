/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:47:38 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/08 17:22:51 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void
	ft_exec_pipe_child(t_node *node, int pfds[2],
					int direction, t_content *minishell)
{
	int	status;

	if (direction == 1)
	{
		close(pfds[0]);
		dup2(pfds[1], STDOUT_FILENO);
		close(pfds[1]);
	}
	else if (direction == 2)
	{
		close(pfds[1]);
		dup2(pfds[0], STDIN_FILENO);
		close(pfds[0]);
	}
	status = ft_exec_node(node, true, minishell);
	(ft_clean_ms(minishell), exit(status));
}

int	ft_get_exit_status(int status)
{
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (WEXITSTATUS(status));
}

static	int	ft_exec_pipeline(t_node *tree, t_content *minishell)
{
	int	status;
	int	pfds[2];
	int	pid_l;
	int	pid_r;

	g_signal.signint_child = true;
	pipe(pfds);
	pid_l = fork();
	if (!pid_l)
		ft_exec_pipe_child(tree->left, pfds, 1, minishell);
	else
	{
		pid_r = fork();
		if (!pid_r)
			ft_exec_pipe_child(tree->right, pfds, 2, minishell);
		else
		{
			(close(pfds[0]), close(pfds[1]),
				waitpid(pid_l, &status, 0), waitpid(pid_r, &status, 0));
			g_signal.signint_child = false;
			return (ft_get_exit_status(status));
		}
	}
	return (ENO_GENERAL);
}

int	ft_exec_node(t_node *tree, bool is_piped, t_content *minishell)
{
	if (!tree)
		return (1);
	if (tree->type == E_PIPE)
		return (ft_exec_pipeline(tree, minishell));
	else
		return (ft_exec_simple_cmd(tree, is_piped, minishell));
	return (ENO_GENERAL);
}
