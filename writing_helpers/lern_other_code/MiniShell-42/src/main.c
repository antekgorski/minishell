/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:43:46 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/08 19:15:52 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_singals	g_signal;

static void	ft_handle_readline_null(t_content *minishell)
{
	gc_collector(NULL, true);
	ft_clear_envlist(minishell);
	rl_clear_history();
	tcsetattr(STDIN_FILENO, TCSANOW, &minishell->terminal);
	exit(minishell->exit_state);
}

static void	ft_start_exec(t_content *minishell)
{
	signal(SIGQUIT, ft_sigquit_handler);
	ft_init_tree(minishell, minishell->parsed);
	if (g_signal.heredoc_sigint)
	{
		ft_clear_parse(&minishell->parsed, minishell);
		g_signal.heredoc_sigint = false;
	}
	minishell->exit_state = ft_exec_node(minishell->parsed, false, minishell);
	ft_clear_parse(&minishell->parsed, minishell);
}

static int	ft_minishell_loop(t_content *minishell)
{
	while (1)
	{
		ft_init_signals(minishell);
		minishell->line = readline(PROMPT);
		if (minishell->line == NULL)
		{
			ft_handle_readline_null(minishell);
		}
		if (minishell->line)
			add_history(minishell->line);
		minishell->tokens = ft_tokens(minishell);
		if (!minishell->tokens)
			continue ;
		minishell->parsed = ft_parse(minishell);
		if (minishell->parse_error.type)
		{
			ft_ex_parse_err(minishell);
			continue ;
		}
		ft_start_exec(minishell);
	}
	gc_collector(NULL, true);
	return (ft_clean_ms(minishell), minishell->exit_state);
}

static void	ft_init_minishell(t_content *minishell, char **env)
{
	(void)minishell;
	minishell->error = 0;
	minishell->exit_state = 0;
	minishell->envir = env;
	minishell->enviroment = NULL;
	minishell->parse_error.type = 0;
	ft_init_env(minishell);
	minishell->stdin = dup(0);
	minishell->stdout = dup(1);
	tcgetattr(STDIN_FILENO, &minishell->terminal);
}

int	main(int argc, char **argv, char **env)
{
	t_content	minishell;

	((void)argv, (void)argc, (void)env);
	ft_init_minishell(&minishell, env);
	ft_minishell_loop(&minishell);
	gc_collector(NULL, true);
	return (ft_clean_ms(&minishell), minishell.exit_state);
}
