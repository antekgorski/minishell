/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/30 18:55:24 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	handle_command_not_found(char **args, char **envp,
		t_minishell *minishell)
{
	print_error_message(args[0], "command not found");
	clean_and_free(NULL, envp, minishell, 127);
}

void	clean_and_free(char *exec_path, char **envp, t_minishell *minishell,
		int exit_code)
{
	if (exec_path)
		free(exec_path);
	if (envp)
		ft_free_split2(&envp);
	if (minishell)
		ft_shell_free(minishell);
	exit(exit_code);
}

void	print_error_message(char *arg, char *error_message)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error_message, 2);
	ft_putstr_fd("\n", 2);
}

int	check_redirection_access(t_cmd *cmd, t_minishell *minishell)
{
	t_redir	*redir;

	redir = cmd->redirs;
	while (redir)
	{
		if (redir->type == OREDIR || redir->type == APPEND)
		{
			if (ft_strchr(redir->filename, '/'))
			{
				if (access(redir->filename, F_OK) == -1)
				{
					print_error_message(redir->filename,
						"No such file or directory");
					minishell->f_signal = 1;
					return (1);
				}
			}
		}
		redir = redir->next;
	}
	return (0);
}

int	check_pipeline_redirections(t_cmd *cmds, t_minishell *minishell)
{
	t_cmd	*temp;

	temp = cmds;
	while (temp)
	{
		if (check_redirection_access(temp, minishell))
			return (1);
		temp = temp->next;
	}
	return (0);
}
