/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:33:16 by agorski           #+#    #+#             */
/*   Updated: 2024/12/15 22:24:44 by agorski          ###   ########.fr       */
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

int	main(void)
{
	t_minishell	minishell;

	minishell.lexter_tab = NULL;
	while (1)
	{
		minishell.line = readline(PROMPT);
		if (!minishell.line)
			break ;
		if (minishell.line)
		{
			add_history(minishell.line);
			parse(&minishell);
			while (*minishell.lexter_tab)
			{
				printf("%s\n", *minishell.lexter_tab);
				minishell.lexter_tab++;
			}
		}
		free(minishell.line);
	}
}
