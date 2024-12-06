/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:02:12 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/05/24 18:12:50 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Processes the user's input.
 *
 * This function takes the user's input and the shell state as parameters. 
 * It adds the input to the history, tokenizes the input, checks for memory 
 * allocation errors, parses the tokens, and executes the corresponding 
 * commands. It then frees the memory allocated for the commands and tokens.
 *
 * @param user_input The user's input.
 * @param shell The current state of the shell.
 */
void	handle_input(char *user_input, t_minishell *shell)
{
	add_history(user_input);
	shell->token_list = init_token_list(tokenizer(user_input, shell));
	check_free(user_input);
	if (parser(shell))
		execute(shell);
	free_commands(shell);
	free_tokens(shell->token_list);
	shell->token_list = NULL;
}

/**
 * @brief Checks if the input consists only of spaces.
 *
 * This function takes a string as input and checks if it consists only of 
 * space characters.
 * It returns true if the input is only spaces, and false otherwise.
 *
 * @param user_input The string to check.
 * @return true if the input is only spaces, false otherwise.
 */
bool	is_spaces(char *user_input)
{
	int	i;

	i = 0;
	while (user_input[i])
	{
		if (!ft_isspace(user_input[i]))
			return (false);
		i++;
	}
	return (true);
}
