/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2024/12/18 13:19:27 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Pobiera bieżące ustawienia terminala
// Wyłącza ECHOCTL (odpowiada za wyświetlanie ^C, ^Z, itp.)
// Wprowadza zmiany
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
// Usuwa '^\' z terminala
static void	sigquit_handler(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay();
	write(STDERR_FILENO, "  \b\b", 4);
}

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
