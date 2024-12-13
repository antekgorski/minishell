/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 21:41:27 by sehosaf           #+#    #+#             */
/*   Updated: 2024/06/19 21:03:48 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

/**
 * @brief The export command adds a new environment variable
 * or modifies an existing one.
 * @param shell The shell structure
 * @param key_value The key and value of the environment variable as a string.
 * @return The exit status
 */
int	cmd_export(t_shell *shell, const char *key_value)
{
	if (is_valid_env_var(key_value))
		create_env_var(&shell->env, key_value);
	else
	{
		ft_putstr_fd("minishell: export: `", STDERR_FILENO);
		ft_putstr_fd((char *)key_value, STDERR_FILENO);
		ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
