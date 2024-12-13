/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:16:31 by sehosaf           #+#    #+#             */
/*   Updated: 2024/07/17 09:32:39 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "environment.h"

/**
 * @brief Frees the shell structure and exits the shell with the exit status.
 * @param shell The shell structure to free
 */
void	cleanup_and_exit_shell(t_shell *shell)
{
	int	exit_status;

	if (!shell)
		exit(EXIT_SUCCESS);
	exit_status = shell->exit_status;
	if (exit_status < 0 || exit_status > 255)
		exit_status = 255;
	if (shell->env)
	{
		free_env(shell->env);
		shell->env = NULL;
	}
	shell = NULL;
	exit(exit_status);
}
