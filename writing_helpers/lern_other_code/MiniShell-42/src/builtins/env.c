/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:02:16 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/08 19:04:49 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_extract_key(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (gc_collector(ft_substr(str, 0, i), false));
		i++;
	}
	return (ft_strdup(str));
}

char	*ft_extract_value(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			i++;
			return (gc_collector(ft_substr(str, i, ft_strlen(str) - i), false));
		}
		i++;
	}
	return (NULL);
}

void	ft_init_env(t_content *minishell)
{
	int		i;
	char	**env;
	char	*key;
	char	*value;

	i = 0;
	env = minishell->envir;
	while (env[i])
	{
		key = ft_extract_key(env[i]);
		value = ft_extract_value(env[i]);
		ft_update_env_list(key, value, true, minishell);
		i++;
	}
}

int	md_env(t_content *minishell)
{
	t_env	*replic;

	replic = minishell->enviroment;
	while (replic)
	{
		if (replic->value == NULL)
		{
			replic = replic->next;
			continue ;
		}
		printf("%s=%s\n", replic->key, replic->value);
		replic = replic->next;
	}
	if (replic)
	{
		if (replic->value != NULL)
			printf("%s=%s\n", replic->key, replic->value);
	}
	return (1);
}
