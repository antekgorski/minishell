/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:54:02 by fursini           #+#    #+#             */
/*   Updated: 2024/05/25 10:16:57 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Handles the 'env' shell command.
 *
 * This function is responsible for handling the 'env' shell command. 
 * It prints all environment variables stored in the shell instance to the 
 * standard output, each on a new line.
 *
 * @param shell A pointer to the shell instance where the environment variables 
 * are stored.
 * @return int Returns 0 after successfully printing all environment variables.
 */
int	env(t_minishell *shell)
{
	t_token	*env_list;

	env_list = shell->env_list;
	while (env_list)
	{
		ft_putstr_fd(env_list->str, 1);
		ft_putstr_fd("\n", 1);
		env_list = env_list->next;
	}
	return (0);
}
