/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2024/12/20 19:09:58 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	is_valid_key(char *key)
{
	int	i;

	if (!key || !ft_isalpha(key[0]))
		return (0);
	i = 0;
	while (key[i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	add_or_update_env(t_minishell *minishell, char *arg)
{
	char	**split;
	t_list	*existing_env;

	if (!ft_strchr(arg, '='))
	{
		ft_putstr_fd("export: not a valid identifier: ", 2);
		ft_putendl_fd(arg, 2);
		return ;
	}
	split = ft_split_env(arg);
	if ((!split || !is_valid_key(split[0])) && split[1])
	{
		ft_putstr_fd("export: not a valid identifier: ", 2);
		ft_putendl_fd(arg, 2);
		ft_free_split(split);
		return ;
	}
	existing_env = ft_find_env(minishell->m_env, split[0]);
	if (existing_env)
	{
		ft_free_split((char **)existing_env->content);
		existing_env->content = split;
	}
	else
		ft_lstadd_back(&minishell->m_env, ft_lstnew(split));
}

int	ft_export(t_minishell *minishell, char **args)
{
	int	i;

	if (!args[1])
	{
		ft_env(minishell);
		return (0);
	}
	i = 1;
	while (args[i])
	{
		add_or_update_env(minishell, args[i]);
		i++;
	}
	return (0);
}
