/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_colector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:44:46 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/08 18:56:27 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	del(void *to_free)
{
	free(to_free);
	to_free = NULL;
}

void	*gc_collector(void *list, bool free)
{
	static t_list	*to_free;

	if (free)
	{
		ft_lstclear(&to_free, del);
		return (NULL);
	}
	else
	{
		ft_lstadd_back(&to_free, ft_lstnew(list));
		return (list);
	}
}

void	ft_clear_envlist(t_content *minishell)
{
	t_env	*envlist;
	t_env	*envlist_free;

	envlist = minishell->enviroment;
	while (envlist)
	{
		envlist_free = envlist;
		envlist = envlist->next;
		free(envlist_free);
	}
	minishell->enviroment = NULL;
}

void	ft_clean_ms(t_content *minishell)
{
	gc_collector(NULL, true);
	ft_clear_parse(&minishell->parsed, minishell);
	ft_clear_envlist(minishell);
	rl_clear_history();
	tcsetattr(STDIN_FILENO, TCSANOW, &minishell->terminal);
}
