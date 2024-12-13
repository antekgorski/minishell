/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:27:45 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/05/25 12:37:19 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Handles a specific signal and clears the input line.
 * 
 * @param signal The signal that triggered this function. Unused.
 */
void	clear_input_signal(int signal)
{
	(void)signal;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_exit_status = 130;
}

/**
 * @brief Handles a specific signal and clears the input line 
 * (alternate version).
 * 
 * @param signal The signal that triggered this function. Unused.
 */
void	clear_input_signal_2(int signal)
{
	(void)signal;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	g_exit_status = 130;
}
