/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:54:21 by sehosaf           #+#    #+#             */
/*   Updated: 2024/08/01 18:40:01 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include <errno.h>

static void	sigint_handler(int signum);
static void	kill_all_child_processes(int signal);

extern pid_t	g_pids[MAX_CMD];

/**
 * @brief Handles signals in non-interactive mode.
 * @note Replaces SIGQUIT handler with SIG_IGN.
 * @note Ignores SIGINT signal and prints a newline character.
 * @note SIGINT and SIGQUIT are blocked while the signal handler is running.
 */
void	non_interactive_signal_handlers(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGINT);
	sigaddset(&act.sa_mask, SIGQUIT);
	act.sa_handler = kill_all_child_processes;
	act.sa_flags = 0;
	if (sigaction(SIGINT, &act, NULL))
		perror(ERR_SIGINT);
	if (sigaction(SIGQUIT, &act, NULL))
		perror(ERR_SIGQUIT);
}

/**
 * @brief Handles signals in interactive mode.
 * @note This function sets the signal handler for SIGINT to reset the prompt.
 */
void	interactive_signal_handlers(void)
{
	struct sigaction	sa_int;
	struct sigaction	sa_quit;

	sigemptyset(&sa_int.sa_mask);
	sigemptyset(&sa_quit.sa_mask);
	sigaddset(&sa_int.sa_mask, SIGINT);
	sigaddset(&sa_quit.sa_mask, SIGQUIT);
	sa_int.sa_handler = sigint_handler;
	sa_quit.sa_handler = SIG_IGN;
	sa_int.sa_flags = 0;
	sa_quit.sa_flags = 0;
	if (sigaction(SIGINT, &sa_int, NULL))
		perror(ERR_SIGINT);
	if (sigaction(SIGQUIT, &sa_quit, NULL))
		perror(ERR_SIGQUIT);
}

/**
 * @note It will interrupt the shell and print a newline character.
 */
static void	sigint_handler(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

/**
 * @note SIGINT is ignored by printing a newline character while
 * in non-interactive mode.
 */
static void	kill_all_child_processes(int signal)
{
	int	i;
	int	status;

	i = -1;
	while (g_pids[++i] != 0)
	{
		if (kill(g_pids[i], signal) == -1)
			perror(ERR_KILL);
		else
		{
			if (signal == SIGQUIT)
				ft_putendl_fd("Quit", 1);
			if (waitpid(g_pids[i], &status, 0) == -1)
				if (errno != ECHILD)
					perror("waitpid");
		}
		g_pids[i] = 0;
	}
	rl_on_new_line();
}
