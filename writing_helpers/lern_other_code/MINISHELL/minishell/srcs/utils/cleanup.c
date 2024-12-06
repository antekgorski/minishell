/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:51:57 by fursini           #+#    #+#             */
/*   Updated: 2024/05/25 13:15:15 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Frees the environment variables array.
 * 
 * @param envp The environment variables array.
 */
static void	free_envp(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return ;
	while (envp[i])
	{
		check_free(envp[i]);
		i++;
	}
	check_free(envp);
}

/**
 * @brief Frees the IO redirection structure.
 * 
 * @param io_redir The IO redirection structure.
 */
static void	free_io_redir(t_io_redir *io_redir)
{
	if (io_redir)
	{
		check_free(io_redir->input);
		check_free(io_redir->output);
		check_free(io_redir->heredoc);
		check_free(io_redir);
	}
}

/**
 * @brief Frees the tokens linked list.
 * 
 * @param token The head of the tokens linked list.
 */
void	free_tokens(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (token)
	{
		tmp = token;
		token = token->next;
		check_free(tmp->str);
		check_free(tmp);
	}
}

/**
 * @brief Frees the commands linked list.
 * 
 * @param shell The main shell structure containing the commands linked list.
 */
void	free_commands(t_minishell *shell)
{
	t_command	*tmp;
	t_command	*next;

	if (!shell->command)
		return ;
	tmp = shell->command;
	while (tmp)
	{
		next = tmp->next;
		check_free(tmp->name);
		check_free(tmp->fd_pipe);
		free_matrix(tmp->args);
		free_io_redir(tmp->io_redir);
		check_free(tmp);
		tmp = next;
	}
	shell->command = NULL;
}

/**
 * @brief Frees the main shell structure and exits the program.
 * 
 * @param shell The main shell structure.
 */
void	free_minishell(t_minishell *shell)
{
	fd_close(shell->command);
	if (shell->command)
		redir_reset(shell->command->io_redir);
	free_commands(shell);
	free_envp(shell->envp);
	free_tokens(shell->env_list);
	free_tokens(shell->token_list);
	clear_history();
	exit(g_exit_status);
}
