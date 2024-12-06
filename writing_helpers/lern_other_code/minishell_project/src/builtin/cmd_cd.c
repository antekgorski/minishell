/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:37:41 by sehosaf           #+#    #+#             */
/*   Updated: 2024/07/17 11:30:10 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static bool	is_home_keyword(const char *arg);
static int	update_pwd_env(t_shell *shell, char *old_pwd);

/**
 * @brief Change current working directory
 * @param shell pointer to shell structure
 * @param args arguments passed to cd command including `cd` command itself
 * @return int `EXIT_SUCCESS` if success, `EXIT_FAILURE` otherwise
 */
int	cmd_cd(t_shell *shell, char **args)
{
	char	*change_to;
	char	*old_pwd;

	if (args[1] == NULL || is_home_keyword(args[1]))
	{
		change_to = get_env_val(shell->env, "HOME");
		if (change_to == NULL)
		{
			ft_putendl_fd(ERR_NO_HOME, 2);
			return (EXIT_FAILURE);
		}
	}
	else
		change_to = args[1];
	if (get_env_val(shell->env, "PWD") != NULL)
		old_pwd = ft_strdup(get_env_val(shell->env, "PWD"));
	else
		old_pwd = getcwd(NULL, 0);
	if (chdir(change_to) != 0)
	{
		ft_putstr_fd(ERR_NO_CD, 2);
		ft_putendl_fd(change_to, 2);
		return (free(old_pwd), EXIT_FAILURE);
	}
	return (update_pwd_env(shell, old_pwd));
}

static bool	is_home_keyword(const char *arg)
{
	if (arg[0] == '~' && arg[1] == '\0')
		return (true);
	else if (ft_strcmp(arg, "--") == 0)
		return (true);
	else if (ft_strcmp(arg, "$HOME") == 0)
		return (true);
	else if (ft_strcmp(arg, "${HOME}") == 0)
		return (true);
	return (false);
}

static int	update_pwd_env(t_shell *shell, char *old_pwd)
{
	char	*new_pwd;

	new_pwd = getcwd(NULL, 0);
	if (new_pwd == NULL)
	{
		ft_putendl_fd(ERR_RET_CWD, 2);
		return (free(old_pwd), EXIT_FAILURE);
	}
	if (set_env_var(shell->env, "OLDPWD", old_pwd) == EXIT_FAILURE)
	{
		free(new_pwd);
		return (free(old_pwd), EXIT_FAILURE);
	}
	if (set_env_var(shell->env, "PWD", new_pwd) == EXIT_FAILURE)
	{
		free(new_pwd);
		return (free(old_pwd), EXIT_FAILURE);
	}
	free(old_pwd);
	free(new_pwd);
	return (EXIT_SUCCESS);
}
