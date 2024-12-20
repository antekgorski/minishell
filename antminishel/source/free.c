/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:23:49 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 11:38:25 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_shell_free(t_minishell *minishell)
{
	tab_free(&minishell->lexter_tab);
	free(minishell->line);
	env_free(minishell->m_env);
	ft_token_free(&minishell->token_list);
}

void	tab_free(char ***lexter_tab)
{
	int	i;

	if (*lexter_tab == NULL)
		return ;
	i = 0;
	while ((*lexter_tab)[i] && (*lexter_tab)[i] != NULL)
	{
		free((*lexter_tab)[i]);
		(*lexter_tab)[i] = NULL;
		i++;
	}
	free(*lexter_tab);
	*lexter_tab = NULL;
}

void	env_free(t_list *env)
{
	t_list	*tmp;
	char	**env_vars;

	if (env == NULL)
		return ;
	while (env)
	{
		tmp = env;
		env_vars = (char **)env->content;
		if (env_vars)
		{
			free(env_vars[0]);
			free(env_vars[1]);
			free(env_vars);
		}
		env = env->next;
		free(tmp);
	}
}

void	ft_token_free(t_list **token_list)
{
	t_list	*tmp;
	t_token	*token;

	if (*token_list == NULL)
		return ;
	while (*token_list)
	{
		tmp = *token_list;
		token = (t_token *)(*token_list)->content;
		if (token != NULL)
		{
			free(token);
			token = NULL;
		}
		*token_list = (*token_list)->next;
		if (tmp != NULL)
		{
			free(tmp);
			tmp = NULL;
		}
	}
	*token_list = NULL;
}
