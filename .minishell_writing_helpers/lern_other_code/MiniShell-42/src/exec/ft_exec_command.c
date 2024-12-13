/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:50:06 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/08 18:51:37 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_redirection(t_node *node)
{
	t_io_node	*tmp_io;
	int			tmp_status;

	tmp_io = node->io_node;
	while (tmp_io)
	{
		if (tmp_io->type == E_OUT
			&& ft_out(tmp_io, &tmp_status) != ENO_SUCCESS)
			return (tmp_status);
		else if (tmp_io->type == E_IN
			&& ft_in(tmp_io, &tmp_status) != ENO_SUCCESS)
			return (tmp_status);
		else if (tmp_io->type == E_APPEND
			&& ft_append(tmp_io, &tmp_status) != ENO_SUCCESS)
			return (tmp_status);
		else if (tmp_io->type == E_HEREDOC)
			(dup2(tmp_io->here_doc, 0), close(tmp_io->here_doc));
		tmp_io = tmp_io->next;
	}
	return (ENO_SUCCESS);
}

void	ft_reset_stds(bool is_piped, t_content *minishell)
{
	if (is_piped)
		return ;
	dup2(minishell->stdin, 0);
	dup2(minishell->stdout, 1);
}

static int	ft_exec_child(t_node *node, t_content *minishell)
{
	t_path	path_status;
	int		tmp_status;
	int		fork_pid;

	g_signal.signint_child = true;
	fork_pid = fork();
	if (!fork_pid)
	{
		tmp_status = ft_check_redirection(node);
		if (tmp_status != ENO_SUCCESS)
			(ft_clean_ms(minishell), exit(ENO_GENERAL));
		path_status = ft_get_path((node -> expand_args)[0], minishell);
		if (path_status.err.no != ENO_SUCCESS)
		{
			tmp_status = ft_err_msg(path_status.err);
			(ft_clean_ms(minishell), exit(tmp_status));
		}
		if (execve(path_status.path, node -> expand_args,
				minishell->envir) == -1)
			(ft_clean_ms(minishell), exit(1));
	}
	waitpid(fork_pid, &tmp_status, 0);
	g_signal.signint_child = false;
	return (ft_get_exit_status(tmp_status));
}

int	ft_exec_simple_cmd(t_node *node, bool is_piped, t_content *minishell)
{
	int		tmp_status;

	if (!node->expand_args)
	{
		tmp_status = ft_check_redirection(node);
		return (ft_reset_stds(is_piped, minishell), (tmp_status && 1));
	}
	else if (ft_is_builtin((node->expand_args)[0]))
	{
		tmp_status = ft_check_redirection(node);
		if (tmp_status != ENO_SUCCESS)
			return (ft_reset_stds(is_piped, minishell), tmp_status);
		tmp_status = ft_exec_builtin(node->expand_args, minishell);
		return (ft_reset_stds(is_piped, minishell), tmp_status);
	}
	else
		return (ft_exec_child(node, minishell));
}
