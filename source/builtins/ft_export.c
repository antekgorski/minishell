/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/25 12:40:13 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int	handle_invalid_identifier(char **split)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(split[0], 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	if (split)
		ft_free_split(split);
	return (2);
}

int	prepare_env_split(t_minishell *minishell, char *arg, char ***split)
{
	t_list	*existing_env;

	if (!ft_strchr(arg, '='))
	{
		existing_env = ft_find_env(minishell->m_env, arg);
		if (existing_env)
			return (0);
		*split = malloc(sizeof(char *) * 2);
		if (!*split)
			return (1);
		(*split)[0] = ft_strdup(arg);
		(*split)[1] = NULL;
		if (!is_valid_key(arg))
			return (handle_invalid_identifier(*split));
	}
	else
	{
		*split = ft_split_env(arg);
		if (!*split || !is_valid_key((*split)[0]))
			return (handle_invalid_identifier(*split));
	}
	return (1);
}

static void	update_env_list(t_minishell *minishell, char **split)
{
	t_list	*existing_env;

	existing_env = ft_find_env(minishell->m_env, split[0]);
	if (existing_env)
	{
		ft_free_split((char **)existing_env->content);
		existing_env->content = split;
	}
	else
	{
		ft_lstadd_back(&minishell->m_env, ft_lstnew(split));
	}
}

static int	add_or_update_env(t_minishell *minishell, char *arg)
{
	char	**split;
	int		result;

	result = prepare_env_split(minishell, arg, &split);
	if (result == 0)
		return (0);
	if (result == 2)
		return (1);
	if (result == 1)
	{
		update_env_list(minishell, split);
		return (0);
	}
	return (1);
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
