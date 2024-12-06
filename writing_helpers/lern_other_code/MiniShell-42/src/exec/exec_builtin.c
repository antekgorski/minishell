/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:24:59 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/08 17:17:52 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exec_builtin(char **args, t_content *minishell)
{
	if (ft_strcmp(args[0], "echo") == 0)
		return (md_echo(args));
	if (ft_strcmp(args[0], "cd") == 0)
		return (md_cd(args[1], minishell));
	if (ft_strcmp(args[0], "env") == 0)
		return (md_env(minishell));
	if (ft_strcmp(args[0], "pwd") == 0)
		return (md_pwd());
	if (ft_strcmp(args[0], "unset") == 0)
		return (md_unset(minishell, args));
	if (ft_strcmp(args[0], "export") == 0)
		return (md_export(args, minishell));
	md_exit(minishell);
	return (ENO_GENERAL);
}

bool	ft_is_builtin(char *arg)
{
	if (!arg)
		return (false);
	if (!ft_strcmp(arg, "echo")
		|| !ft_strcmp(arg, "cd")
		|| !ft_strcmp(arg, "exit")
		|| !ft_strcmp(arg, "pwd")
		|| !ft_strcmp(arg, "export")
		|| !ft_strcmp(arg, "unset")
		|| !ft_strcmp(arg, "env"))
		return (true);
	return (false);
}
