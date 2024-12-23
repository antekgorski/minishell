/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:52:04 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 18:45:35 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char * to char ** [0] = var_name [1] = var_value
char	**ft_split_env(char *env)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_calloc(3, sizeof(char *));
	if (!split)
		ft_panic("Malloc failed", 1);
	while (env[i] && env[i] != '=')
		i++;
	split[0] = ft_substr(env, 0, i);
	if (env[i] == '=')
		split[1] = ft_strdup(&env[i + 1]);
	else
		split[1] = ft_strdup("");
	split[2] = NULL;
	return (split);
}

void	env_start(t_minishell *minishell, char **envp)
{
	char	**tmp_env;

	tmp_env = envp;
	while (*tmp_env)
	{
		ft_lstadd_back(&minishell->m_env, ft_lstnew(ft_split_env(*tmp_env)));
		tmp_env++;
	}
}
