/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2024/12/18 21:25:06 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Retrieves the current terminal settings
// Disables ECHOCTL (responsible for displaying ^C, ^Z, etc.)
// Applies the changes to the terminal
static void	disable_signal_echo(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// crl + c
// print new promt
static void	sigint_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

// ctrl + '\'
// Do nothing
static void	sigquit_handler(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay();
}

// Initialize signals
// Disable ECHOCTL (responsible for displaying ^C, ^Z, etc.)
// Handle SIGINT and SIGQUIT signals
void	signal_initialization(void)
{
	disable_signal_echo();
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}

// ctrl + D
// exit shell
void	handle_input(char *input)
{
	if (!input)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		exit(0);
	}
}