/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:33:16 by agorski           #+#    #+#             */
/*   Updated: 2024/12/17 12:25:28 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
main function for minishell
it reads the line from the user and then parses it
if the line is empty it breaks the loop
if the line is not empty it adds it to the history and then parses it
then it frees the line
and the loop continues
*/

void main_loop(t_minishell *minishell)
{
	while (1)
	{
		minishell->line = readline(PROMPT);
		if (!minishell->line)
			break ;
		if (minishell->line)
		{
			if (minishell->line[0] != '\0')
				add_history(minishell->line);
			parse(minishell);
		}
		free(minishell->line);
	}
}

int	main(void)
{
	t_minishell	minishell;

	minishell.lexter_tab = NULL;
	main_loop(&minishell);
}
// valgrind --leak-check=full --track-origins=yes ./minishell
// valgrind --leak-check=full --track-origins=yes --suppressions=valgrind_ignore.supp ./minishell
//valgrind --leak-check=full --show-leak-kinds=all --suppressions=valgrind_ignore.supp ./minishell