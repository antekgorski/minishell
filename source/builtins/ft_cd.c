/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/27 12:11:38 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	free_env_var(char **env_var)
{
	int	i;

	i = 0;
	if (env_var[i])
	{
		free(env_var[i]);
		env_var[i] = NULL;
		i++;
	}
}

static int	ft_update_env(char *key, char *value, t_list **env)
{
	t_list	*current;
	char	**env_var;
	char	**new_env;

	current = *env;
	while (current)
	{
		env_var = (char **)current->content;
		if (ft_strcmp(env_var[0], key) == 0)
		{
			free(env_var[1]);
			env_var[1] = ft_strdup(value);
			return (0);
		}
		current = current->next;
	}
	new_env = malloc(sizeof(char *) * 3);
	if (!new_env)
		return (-1);
	new_env[0] = ft_strdup(key);
	new_env[1] = ft_strdup(value);
	new_env[2] = NULL;
	ft_lstadd_back(env, ft_lstnew(new_env));
	free_env_var(new_env);
	return (0);
}

static char	*ft_get_cwd(void)
{
	char	*cwd;
	char	*dup;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (NULL);
	dup = ft_strdup(cwd);
	free(cwd);
	return (dup);
}

static int	to_many_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	if (i > 2)
	{
		write(2, "cd: too many arguments\n", 23);
		return (1);
	}
	return (0);
}

int	ft_cd(char **args, t_minishell *minishell)
{
	char	*old_pwd;
	char	*new_pwd;
	char	*home;

	if (to_many_args(args))
		return (1);
	old_pwd = ft_get_env(minishell->m_env, "PWD");
	if (!args[1])
	{
		home = ft_get_env(minishell->m_env, "HOME");
		if (!home)
			return (write(2, "cd: HOME not set\n", 17), 1);
		if (chdir(home) != 0)
			return (perror("cd"), 1);
	}
	else if (chdir(args[1]) != 0)
		return (perror("cd"), 1);
	new_pwd = ft_get_cwd();
	if (!new_pwd)
		return (perror("getcwd"), 1);
	if (old_pwd)
		ft_update_env("OLDPWD", old_pwd, &minishell->m_env);
	ft_update_env("PWD", new_pwd, &minishell->m_env);
	free(new_pwd);
	return (0);
}
