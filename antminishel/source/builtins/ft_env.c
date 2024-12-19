/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2024/12/19 16:17:00 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_minishell *minishell)
{
	t_list	*current;
	char	**env_vars;

	if (minishell->m_env == NULL)
		return (1);
	current = minishell->m_env;
	while (current != NULL)
	{
		env_vars = (char **)current->content;
		printf("%s=%s\n", env_vars[0], env_vars[1]);
		current = current->next;
	}
	return (0);
}
