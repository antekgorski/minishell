/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:22:59 by fursini           #+#    #+#             */
/*   Updated: 2024/05/25 11:51:52 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Checks for syntax errors in a single token.
 *
 * This function checks for syntax errors in a single token. It checks for cases
 * like a pipe character without a next token, redirection without a next token
 * or with another redirection or pipe as the next token, and two consecutive 
 * pipe characters.
 *
 * @param token The token to be checked.
 * @return true if a syntax error is found, false otherwise.
 */
static bool	check_error_token(t_token *token)
{
	if (token->type == PIPE && !token->next)
	{
		print_error("syntax error near unexpected token `newline`");
		g_exit_status = 2;
		return (true);
	}
	else if (token_is_redir(token->type) && (!token->next || (token->next
				&& (token_is_redir(token->next->type)
					|| token->next->type == PIPE))))
	{
		print_error("syntax error near unexpected token");
		g_exit_status = 2;
		return (true);
	}
	else if (token->type == PIPE && token->next->type == PIPE)
	{
		print_error("syntax error near unexpected token `|`");
		g_exit_status = 2;
		return (true);
	}
	return (false);
}

/**
 * @brief Checks for syntax errors in a list of tokens.
 *
 * This function checks for syntax errors in a list of tokens. It checks for a 
 * case where the first token is a pipe character, and then iterates over the 
 * list of tokens and checks each one for syntax errors using the 
 * check_error_token function.
 *
 * @param shell The shell containing the list of tokens.
 * @return true if a syntax error is found, false otherwise.
 */
bool	check_error_token_list(t_minishell *shell)
{
	t_token	*tmp;

	tmp = shell->token_list;
	if (!tmp)
		return (true);
	if (tmp->type == PIPE)
	{
		print_error("minishell: syntax error near unexpected token `|`");
		g_exit_status = 2;
		return (true);
	}
	while (tmp)
	{
		if (check_error_token(tmp))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

/**
 * @brief Prints an error message.
 *
 * This function prints an error message to the standard error.
 *
 * @param error The error message to be printed.
 */
void	print_error(char *error)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(error, 2);
	ft_putchar_fd('\n', 2);
}

/**
 * @brief Handles an unclosed quote error.
 *
 * This function prints an unclosed quote error message to the 
 * standard error, sets the global exit status to 2,
 * and then exits the shell.
 *
 * @param shell The shell to be exited.
 */
void	unclosed_quote_error(t_minishell *shell)
{
	ft_putstr_fd("minishell: unclosed quote\n", 2);
	g_exit_status = 2;
	exit_minishell(shell, NULL);
}
