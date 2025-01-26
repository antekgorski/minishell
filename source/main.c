/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:33:16 by agorski           #+#    #+#             */
/*   Updated: 2025/01/26 21:11:58 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function to handle the input from the user
 */
static char	*s_input(char *line)
{
	char	*temp;
	int		i;

	i = 0;
	temp = line;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			temp[i] = '\0';
			break ;
		}
		i++;
	}
	return (temp);
}

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
	while (1)
	{
		minishell->line = readline("\033[36m""@nt->""\033[92m""p@w>""\033[0m");
		handle_input(minishell->line, minishell);
		if (minishell->line)
		{
			if (minishell->line[0] != '\0')
				add_history(s_input(minishell->line));
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
	minishell->l_hdr = NULL;
	minishell->cmd_list = NULL;
	env_start(minishell, envp);
	signal_initialization();
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	minishell;

	(void)argc;
	(void)argv;
	minishell_init(&minishell, envp);
	main_loop(&minishell);
}
