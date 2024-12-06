/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:55:07 by fursini           #+#    #+#             */
/*   Updated: 2024/05/25 15:30:25 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long long	g_exit_status = 0;

int	main(int argc, char **argv, char **envp)
{
	t_minishell		shell;
	char			*input;

	printf("%s", INTRO_MSG);
	init_parameters(argc, argv, &shell, envp);
	while (1)
	{
		signal (SIGINT, clear_input_signal);
		input = readline(PROMPT);
		signal(SIGINT, clear_input_signal_2);
		if (input == NULL)
			exit_minishell(&shell, NULL);
		if (ft_strlen(input) == 0 || is_spaces(input))
		{
			check_free(input);
			continue ;
		}
		handle_input(input, &shell);
	}
	return (0);
}
