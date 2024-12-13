/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:21:32 by sehosaf           #+#    #+#             */
/*   Updated: 2024/06/19 20:53:00 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

/**
 * @brief The `env` command prints the environment variables.
 * @details The variable environ points to an array of pointers to strings called
 * the "environment". The last pointer in this array has the value NULL.
 * @ref https://linux.die.net/man/7/environ
 * @param shell The shell structure.
 */
int	cmd_env(t_shell *shell)
{
	t_env	*env;

	env = shell->env;
	if (env == NULL)
		return (EXIT_FAILURE);
	while (env)
	{
		ft_putstr_fd(env->key, STDOUT_FILENO);
		ft_putchar_fd('=', STDOUT_FILENO);
		ft_putendl_fd(env->value, STDOUT_FILENO);
		env = env->next;
	}
	return (EXIT_SUCCESS);
}
