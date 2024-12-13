/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:58:54 by fursini           #+#    #+#             */
/*   Updated: 2024/05/25 13:25:04 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Initializes a copy of the environment variables.
 * 
 * @param envp The original environment variables.
 * @return A copy of the environment variables.
 */
static char	**init_envp(char **envp)
{
	int		i;
	char	**new;

	i = 0;
	while (envp[i])
		i++;
	new = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		new[i] = ft_strdup(envp[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

/**
 * @brief Initializes a linked list of environment variables.
 * 
 * @param envp The environment variables.
 * @return A linked list of environment variables.
 */
static t_token	*init_env_list(char **envp)
{
	t_token	*new;
	t_token	*tmp;
	int		i;

	i = 0;
	new = (t_token *)malloc(sizeof(t_token));
	new->str = ft_strdup(envp[i]);
	new->type = 0;
	new->next = NULL;
	new->prev = NULL;
	tmp = new;
	i++;
	while (envp[i])
	{
		tmp->next = (t_token *)malloc(sizeof(t_token));
		tmp->next->str = ft_strdup(envp[i]);
		tmp->next->type = 0;
		tmp->next->prev = tmp;
		tmp->next->next = NULL;
		tmp = tmp->next;
		i++;
	}
	return (new);
}

/**
 * @brief Initializes the parameters of the shell.
 * 
 * @param argc The argument count.
 * @param argv The argument vector.
 * @param shell The shell to initialize.
 * @param envp The environment variables.
 */
void	init_parameters(int argc, char **argv, t_minishell *shell, char **envp)
{
	(void)argc;
	(void)argv;
	shell->command = NULL;
	shell->token_list = NULL;
	shell->envp = init_envp(envp);
	shell->env_list = init_env_list(shell->envp);
}

/**
 * @brief Initializes a linked list of tokens.
 * 
 * @param tokens The tokens to initialize from.
 * @return A linked list of tokens.
 */
t_token	*init_token_list(char **tokens)
{
	t_token	*new;
	t_token	*tmp;
	int		i;

	i = 0;
	new = (t_token *)malloc(sizeof(t_token));
	new->str = ft_strdup(tokens[i]);
	new->type = 0;
	new->next = NULL;
	new->prev = NULL;
	tmp = new;
	i++;
	while (tokens[i])
	{
		tmp->next = (t_token *)malloc(sizeof(t_token));
		tmp->next->str = ft_strdup(tokens[i]);
		tmp->next->type = 0;
		tmp->next->prev = tmp;
		tmp->next->next = NULL;
		tmp = tmp->next;
		i++;
	}
	free_matrix(tokens);
	return (new);
}

/**
 * @brief Initializes a new command.
 * 
 * @return A new command.
 */
t_command	*init_command(void)
{
	t_command	*new;

	new = malloc(sizeof(t_command));
	if (!new)
		return (NULL);
	new->name = NULL;
	new->args = NULL;
	new->pipe = false;
	new->fd_pipe = NULL;
	new->io_redir = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
