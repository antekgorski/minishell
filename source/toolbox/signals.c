/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/26 20:20:13 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sigint_handler_main(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	sigint_handler_child(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
}

static void	sigquit_handler_main(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay();
}

void	signal_initialization(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	signal(SIGINT, sigint_handler_main);
	signal(SIGQUIT, sigquit_handler_main);
}

void	signal_initialization_child(void)
{
	signal(SIGINT, sigint_handler_child);
	signal(SIGQUIT, SIG_DFL);
}
