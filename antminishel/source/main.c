/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:33:16 by agorski           #+#    #+#             */
/*   Updated: 2024/12/19 20:04:33 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
main_loop function
it reads the line from the user and then parses it
if the line is empty it breaks the loop
if the line is not empty it adds it to the history and then parses it
then it frees the line
and the loop continues
*/

void	main_loop(t_minishell *minishell)
{
	signal_initialization();
	while (1)
	{
		minishell->line = readline(PROMPT);
		handle_input(minishell->line);
		if (minishell->line)
		{
			if (minishell->line[0] != '\0')
				add_history(minishell->line);
			parse(minishell);
		}
		free(minishell->line);
	}
}

// function to initialize the minishell struct

void	minishell_init(t_minishell *minishell, char **envp)
{
	minishell->line = NULL;
	minishell->lexter_tab = NULL;
	minishell->m_env = NULL;
	minishell->token_list = NULL;
	minishell->f_signal = 0;
	env_start(minishell, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	minishell;

	(void)argc;
	(void)argv;
	minishell_init(&minishell, envp);
	main_loop(&minishell);
}
