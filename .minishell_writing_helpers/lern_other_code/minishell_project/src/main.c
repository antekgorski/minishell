/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:35:57 by sehosaf           #+#    #+#             */
/*   Updated: 2024/07/18 16:41:09 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char		*line;
	t_pipeline	*p;
	t_shell		shell;

	if (init_environment(&shell) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	while (1)
	{
		interactive_signal_handlers();
		line = readline(PROMPT);
		non_interactive_signal_handlers();
		if (!line)
			exit(EXIT_SUCCESS);
		if (!*line)
		{
			free(line);
			continue ;
		}
		add_history(line);
		p = parse(line, &shell);
		free(line);
		if (p && validate_pipeline(p) == EXIT_SUCCESS)
			execute(p, &shell);
		free_pipeline(p);
	}
}
