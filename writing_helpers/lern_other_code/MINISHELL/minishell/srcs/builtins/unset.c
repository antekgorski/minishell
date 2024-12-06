/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 03:30:42 by fursini           #+#    #+#             */
/*   Updated: 2024/05/25 09:51:10 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Unset a shell variable.
 *
 * This function removes a variable from the shell's environment. 
 * It iterates over the arguments provided in the command, and for each one, 
 * it finds the corresponding environment variable and removes it.
 *
 * @param shell The shell instance where the environment variables are stored.
 * @param cmd The command structure containing the arguments for the unset 
 * command.
 * @return int Always returns 0.
 */
int	unset(t_minishell *shell, t_command *cmd)
{
	t_token	*tmp;
	int		i;

	i = 1;
	while (cmd->args[i])
	{
		tmp = find_env(shell, cmd->args[i]);
		if (tmp)
			token_remove(shell, tmp);
		i++;
	}
	return (0);
}
