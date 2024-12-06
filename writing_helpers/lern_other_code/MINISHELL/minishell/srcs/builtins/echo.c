/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:59:34 by fursini           #+#    #+#             */
/*   Updated: 2024/05/25 10:18:25 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Handles the 'echo' shell command.
 *
 * This function is responsible for handling the 'echo' shell command. 
 * It prints the arguments provided to the command to the standard output. 
 * If the '-n' option is provided as the first argument,
 * it does not output the trailing newline.
 *
 * @param cmd A pointer to the command structure containing the arguments 
 * for the echo command.
 * @return int Returns 0 after successfully printing the arguments.
 */
int	echo(t_command *cmd)
{
	int	i;

	i = 1;
	if (cmd->args[1] && ft_strcmp(cmd->args[1], "-n") == 0)
	{
		while (cmd->args[++i])
		{
			ft_putstr_fd(cmd->args[i], 1);
			if (cmd->args[i + 1])
				ft_putstr_fd(" ", 1);
		}
	}
	else
	{
		while (cmd->args[i])
		{
			ft_putstr_fd(cmd->args[i], 1);
			if (cmd->args[i + 1])
				ft_putstr_fd(" ", 1);
			i++;
		}
		ft_putstr_fd("\n", 1);
	}
	return (0);
}
