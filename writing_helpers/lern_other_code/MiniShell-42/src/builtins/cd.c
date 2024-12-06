/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:06:06 by mjakowic          #+#    #+#             */
/*   Updated: 2024/08/08 19:05:22 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_change_pwd(t_content *minishell)
{
	char	*cwd;

	cwd = gc_collector(getcwd(NULL, 0), false);
	if (!cwd)
		return (0);
	return (ft_update_env_list("PWD", cwd, false, minishell), 0);
}

static int	ft_cd_home(t_content *minishell)
{
	char	*home;

	ft_update_env_list("OLDPWD",
		ft_get_envlst_val("PWD", minishell), false, minishell);
	home = ft_get_envlst_val("HOME", minishell);
	if (!home)
		return (ft_putstr_fd("minishell: cd: HOME not set\n", 2), 1);
	if (chdir(home) == ENO_SUCCESS)
		return (ft_update_env_list("PWD", home, false, minishell), 0);
	return (0);
}

static int	ft_cd_err_msg(char *err_msg)
{
	ft_putstr_fd("minishell: cd: `", 2);
	ft_putstr_fd(err_msg, 2);
	ft_putstr_fd("': No such file or directory\n", 2);
	return (1);
}

int	md_cd(char *path, t_content *minishell)
{
	if (!path)
		return (ft_cd_home(minishell));
	if (chdir(path) != ENO_SUCCESS)
		return (ft_cd_err_msg(path));
	ft_update_env_list("OLDPWD",
		ft_get_envlst_val("PWD", minishell), false, minishell);
	return (ft_change_pwd(minishell));
}
