/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2024/12/22 01:30:53 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief 	comparing two strings
 * @param s1 first string
 * @param s2 second string
 * @return 0 if strings are equal, 1 if not
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

int	ft_print_env(t_minishell *minishell)
{
	t_list	*current;
	char	**env_vars;

	if (minishell->m_env == NULL)
		return (1);
	current = minishell->m_env;
	while (current != NULL)
	{
		env_vars = (char **)current->content;
		if (env_vars[1])
			printf("declare -x %s=\"%s\"\n", env_vars[0], env_vars[1]);
		else
			printf("declare -x %s\n", env_vars[0]);
		current = current->next;
	}
	return (0);
}
