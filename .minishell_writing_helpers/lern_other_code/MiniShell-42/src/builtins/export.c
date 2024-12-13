/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:19:33 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/08 18:54:15 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_export_err_msg(char *identifier)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(identifier, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}

static	void	ft_export_list(t_content *minishell)
{
	t_env	*list;
	size_t	i;

	list = minishell->enviroment;
	while (list)
	{
		if (list->value != NULL && (ft_strcmp(list->key, "_") != 0))
		{
			printf("declare -x %s=\"", list->key);
			i = 0;
			while ((list->value)[i])
			{
				if ((list->value)[i] == '$' || (list->value)[i] == '"')
					printf("\\%c", (list->value)[i++]);
				else
					printf("%c", (list->value)[i++]);
			}
			printf("\"\n");
		}
		else if (list->value == NULL && (ft_strcmp(list->key, "_") != 0))
			printf("declare -x %s\n", list->key);
		list = list->next;
	}
}

static int	ft_check_key(char *str)
{
	int	i;

	i = 1;
	if (!ft_isalpha(*str) && *str != '_')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	md_export(char **argv, t_content *minishell)
{
	int		i;
	int		exit_s;
	char	*key;

	exit_s = 0;
	i = 1;
	if (!argv[1])
		return (ft_export_list(minishell), 0);
	while (argv[i])
	{
		if (ft_check_key(argv[i]) == 0)
			exit_s = ft_export_err_msg(argv[i]);
		else
		{
			key = ft_extract_key(argv[i]);
			if (ft_env_entry_exists(key, minishell))
				ft_update_env_list(key,
					ft_extract_value(argv[i]), false, minishell);
			else
				ft_update_env_list(key,
					ft_extract_value(argv[i]), true, minishell);
		}
		i++;
	}
	return (exit_s);
}
