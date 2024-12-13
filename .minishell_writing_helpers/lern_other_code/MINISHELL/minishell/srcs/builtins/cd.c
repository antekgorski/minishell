/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:11:51 by fursini           #+#    #+#             */
/*   Updated: 2024/05/25 10:40:02 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Updates the OLDPWD environment variable.
 *
 * This function gets the current working directory and updates the OLDPWD 
 * environment variable with its value.
 *
 * @param shell A pointer to the shell instance where the environment 
 * variables are stored.
 */
static void	oldpwd(t_minishell *shell)
{
	char	cwd[PATH_MAX];
	char	*oldpwd;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return ;
	oldpwd = ft_strjoin("OLDPWD=", cwd);
	if (!oldpwd)
		return ;
	update_env(shell, oldpwd);
	check_free(oldpwd);
}

/**
 * @brief Updates the PWD environment variable.
 *
 * This function gets the current working directory and updates the PWD 
 * environment variable with its value.
 *
 * @param shell A pointer to the shell instance where the environment 
 * variables are stored.
 */
static void	updt_pwd(t_minishell *shell)
{
	char	cwd[PATH_MAX];
	char	*str;

	str = ft_strjoin("PWD=", getcwd(cwd, sizeof(cwd)));
	update_env(shell, str);
	check_free(str);
}

/**
 * @brief Changes the current directory to the home directory.
 *
 * This function changes the current directory to the home directory and 
 * updates the PWD and OLDPWD environment variables.
 *
 * @param shell A pointer to the shell instance where the environment 
 * variables are stored.
 * @return int Returns 0 if the operation was successful, or 1 if the 
 * HOME environment variable is not set.
 */
static int	cd_home(t_minishell *shell)
{
	char	*home;

	oldpwd(shell);
	home = get_env_value("HOME", shell);
	if (!home)
	{
		print_error("cd: HOME not set");
		return (1);
	}
	chdir(home);
	updt_pwd(shell);
	check_free(home);
	return (0);
}

/**
 * @brief Changes the current directory to the directory stored in OLDPWD.
 *
 * This function changes the current directory to the directory stored in 
 * OLDPWD and updates the PWD and OLDPWD environment variables.
 *
 * @param shell A pointer to the shell instance where the environment variables 
 * are stored.
 * @return int Returns 0 if the operation was successful, or 1 if the OLDPWD 
 * environment variable is not set.
 */
static int	cd_oldpwd(t_minishell *shell)
{
	char	*pwd;

	pwd = get_env_value("OLDPWD", shell);
	oldpwd(shell);
	if (!pwd)
	{
		print_error("cd: OLDPWD not set");
		return (1);
	}
	chdir(pwd);
	ft_putendl_fd(pwd, 1);
	updt_pwd(shell);
	check_free(pwd);
	return (0);
}

/**
 * @brief Changes the current directory.
 *
 * This function changes the current directory based on the provided arguments 
 * and updates the PWD and OLDPWD environment variables.
 *
 * @param cmd A pointer to the command structure containing the arguments for 
 * the cd command.
 * @param shell A pointer to the shell instance where the environment variables 
 * are stored.
 * @return int Returns 0 if the operation was successful, or 1 if an error 
 * occurred.
 */
int	cd(t_command *cmd, t_minishell *shell)
{
	int	ret;

	if (!cmd->args[1])
		return (cd_home(shell));
	else if (cmd->args[2])
	{
		print_error("cd: too many arguments");
		return (1);
	}
	else if (ft_strcmp(cmd->args[1], "-") == 0)
		return (cd_oldpwd(shell));
	oldpwd(shell);
	ret = chdir(cmd->args[1]);
	updt_pwd(shell);
	if (ret != 0)
	{
		print_error("cd: No such file or directory");
		return (1);
	}
	return (0);
}
