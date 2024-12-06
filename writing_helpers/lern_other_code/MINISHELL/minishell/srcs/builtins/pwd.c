/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:46:41 by fursini           #+#    #+#             */
/*   Updated: 2024/05/25 09:53:16 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Print the current working directory.
 *
 * This function retrieves the current working directory using the getcwd 
 * function and prints it to the standard output. If the getcwd function 
 * fails, it returns 1, otherwise it returns 0.
 *
 * @return int Returns 0 if the current working directory was successfully 
 * retrieved and printed, otherwise returns 1.
 */
int	pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		ft_putstr_fd(cwd, 1);
		ft_putstr_fd("\n", 1);
		return (0);
	}
	return (1);
}
