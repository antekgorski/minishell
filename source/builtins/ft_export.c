/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/10 16:55:49 by prutkows         ###   ########.fr       */
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

	if (!key || (!ft_isalpha(key[0]) && key[0] != '_'))
		return (0);
	i = 1;
	while (key[i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static int	handle_invalid_identifier(char *arg, char **split)
{
	ft_putstr_fd("export: not a valid identifier: ", 2);
	ft_putendl_fd(arg, 2);
	if (split)
		ft_free_split(split);
	return (1);
}

static int	add_or_update_env(t_minishell *minishell, char *arg)
{
	char	**split;
	t_list	*existing_env;

	if (!ft_strchr(arg, '='))
		return (handle_invalid_identifier(arg, NULL));
	split = ft_split_env(arg);
	if (!split || !is_valid_key(split[0]))
		return (handle_invalid_identifier(arg, split));
	existing_env = ft_find_env(minishell->m_env, split[0]);
	if (existing_env)
	{
		ft_free_split((char **)existing_env->content);
		existing_env->content = split;
	}
	else
		ft_lstadd_back(&minishell->m_env, ft_lstnew(split));
	return (0);
}

int	ft_export(t_minishell *minishell, char **args)
{
	int	i;
	int	status;

	status = 0;
	if (!args[1])
	{
		ft_print_env(minishell);
		return (0);
	}
	i = 1;
	while (args[i])
	{
		if (add_or_update_env(minishell, args[i]) != 0)
			status = 1;
		i++;
	}
	return (status);
}
// static int	add_new_env_variable(t_minishell *minishell, char *key)
// {
// 	char	**split;

// 	split = malloc(sizeof(char *) * 3);
// 	if (!split)
// 		return (handle_invalid_identifier(key, NULL));
// 	split[0] = ft_strdup(key);
// 	if (!split[0])
// 	{
// 		free(split);
// 		return (handle_invalid_identifier(key, NULL));
// 	}
// 	split[1] = ft_strdup("");
// 	if (!split[1])
// 	{
// 		free(split[0]);
// 		free(split);
// 		return (handle_invalid_identifier(key, NULL));
// 	}
// 	split[2] = NULL;
// 	ft_lstadd_back(&minishell->m_env, ft_lstnew(split));
// 	return (0);
// }

// static int	handle_env_with_equals(t_minishell *minishell, char **split,
// 		char *arg)
// {
// 	t_list	*existing_env;

// 	if (!split || !is_valid_key(split[0]))
// 		return (handle_invalid_identifier(arg, split));
// 	existing_env = ft_find_env(minishell->m_env, split[0]);
// 	if (existing_env)
// 	{
// 		ft_putstr_fd("Updating existing variable: ", 1);
// 		ft_putendl_fd(split[0], 1);
// 		ft_free_split((char **)existing_env->content);
// 		existing_env->content = split;
// 	}
// 	else
// 	{
// 		ft_putstr_fd("Adding new variable: ", 1);
// 		ft_putendl_fd(split[0], 1);
// 		ft_lstadd_back(&minishell->m_env, ft_lstnew(split));
// 	}
// 	return (0);
// }
// static int	add_or_update_env(t_minishell *minishell, char *arg)
// {
// 	char	**split;
// 	t_list	*existing_env;

// 	if (ft_strchr(arg, '='))
// 	{
// 		split = ft_split_env(arg);
// 		return (handle_env_with_equals(minishell, split, arg));
// 	}
// 	if (!is_valid_key(arg))
// 		return (handle_invalid_identifier(arg, NULL));
// 	existing_env = ft_find_env(minishell->m_env, arg);
// 	if (!existing_env)
// 		return (add_new_env_variable(minishell, arg));
// 	return (0);
// }
