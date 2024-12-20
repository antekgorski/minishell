/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:43:16 by agorski           #+#    #+#             */
/*   Updated: 2024/12/18 11:55:28 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_panic(char *message, int is_error)
{
	perror(message);
	exit(is_error);
}

// reset prompt after error or syntax error i dont know it is ok.
void	syntax_error(char *message, t_minishell *minishell)
{
	ft_shell_free(minishell);
	printf("%s\n", message);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
