/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:06:51 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/15 07:36:53 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"



// t_token identify_token(char *word) {
//     if (ft_strcmp(word, "|") == 0)
//         return PIPE;
//     else if (ft_strcmp(word, "<") == 0)
//         return IREDIR;
//     else if (ft_strcmp(word, ">") == 0)
//         return OREDIR;
//     else if (ft_strcmp(word, ">>") == 0)
//         return APPEND;
//     else if (ft_strcmp(word, "<<") == 0)
//         return HERDOC;
//     else
//         return CMD;
// }
// t_token_struct	*tokenize_input(char *input)
// {
// 	t_token_struct	*head = NULL;
// 	t_token_struct	*current = NULL;

// 	char *word = strtok(input, " \t");
// 	while (word)
// 	{
// 		t_token type = identify_token(word);
// 		t_token_struct *new_token = malloc(sizeof(t_token_struct));
// 		 if (!new_token) {
//             perror("malloc");
//             return NULL;
//         }
// 		new_token->type = type;
// 		new_token->value = ft_strdup(word);
// 		new_token->prev = current;
// 		new_token->next = NULL;

// 		if (current)
// 			current->next = new_token;
// 		else
// 			head = new_token;

// 		current = new_token;
// 		word = strtok(NULL, " \t");
// 	}
// 	return head;
// }
// char	**collect_command(t_token_struct **tokens)
// {
// 	char	**args = malloc(sizeof(char *) * 256);
// 	int i = 0;

// 	while (*tokens && (*tokens)->type == CMD)
// 	{
// 		args[i++] = ft_strdup((*tokens)->value);
// 		*tokens = (*tokens)->next;
// 	}
// 	args[i] = NULL;
// 	return args;
// }
// void add_redirection(t_cmd *cmd, t_token_struct *token)
// {
// 	t_token_struct *redir = malloc(sizeof(t_token_struct));
// 	if (!redir)
// 	{
// 		perror("malloc");
// 		return;
// 	}
// 	redir->type = token->type;
// 	redir->value = strdup(token->next->value);
// 	redir->prev = NULL;
// 	redir->next = cmd->redirections;

// 	if (cmd->redirections)
// 		cmd->redirections->prev = redir;
// 	cmd->redirections = redir;
// }
// t_cmd	*parse_tokens(t_token_struct *tokens)
// {
// 	t_cmd	*head = NULL;
// 	t_cmd	*current_cmd = NULL;

// 	while (tokens)
// 	{
// 		if (tokens->type == CMD)
// 		{
// 			t_cmd *new_cmd = malloc(sizeof(t_cmd));
// 			if (!new_cmd) {
//                 perror("malloc");
//                 return NULL;
//             }
// 			new_cmd->cmd = collect_command(tokens);
// 			new_cmd->redirections = NULL;
// 			new_cmd->next = NULL;

// 			if (current_cmd)
// 				current_cmd->next = new_cmd;
// 			else
// 				head = new_cmd;

// 			current_cmd = new_cmd;
// 		}
// 		else if (tokens->type >= IREDIR && tokens->type <= HERDOC)
// 		{
// 			if (current_cmd)
// 			{
// 				add_redirection(current_cmd, tokens);
// 			}
// 		}
// 		tokens = tokens->next;
// 	}
// 	return (head);
// }
// // dodać czyszenie cmd!
// static t_cmd	*create_cmd_node(void)
// {
// 	t_cmd	*new_cmd;

// 	new_cmd = malloc(sizeof(t_cmd));
// 	if (!new_cmd)
// 		ft_panic("malloc failed", 1);
// 	new_cmd->cmd = NULL;
// 	new_cmd->infile = NULL;
// 	new_cmd->outfile = NULL;
// 	new_cmd->append = 0;
// 	new_cmd->next = NULL;
// 	return (new_cmd);
// }

// static void	add_arg(t_cmd *cmd, char *arg)
// {
// 	int	i;

// 	i = 0;
// 	while (cmd->cmd && cmd->cmd[i])
// 		i++;
// 	cmd->cmd = realloc(cmd->cmd, sizeof(char *) * (i + 2));
// 	if (!cmd->cmd)
// 		ft_panic("realloc failed", 1);
// 	cmd->cmd[i] = ft_strdup(arg);
// 	cmd->cmd[i + 1] = NULL;
// }

// t_cmd	*parse_tokens(t_minishell *minishell)
// {
// 	t_cmd	*head;
// 	t_cmd	*current;
// 	t_list	*tokens;
// 	t_token_struct	*token_struct;
// 	t_token	token;
// 	char	*value;

// 	head = NULL;
// 	current = NULL;
// 	tokens = minishell->token_list;
// 	while (tokens)
// 	{
// 		// token = *((t_token *)tokens->content);
// 		// value = tokens->content;
// 		token_struct = (t_token_struct *)tokens->content;
// 		token = token_struct->type;
// 		value = token_struct->value;

// 		if (token == CMD)
// 		{
// 			if (!head)
// 			{
// 				head = create_cmd_node();
// 				current = head;
// 			}
// 			else if (current->cmd && current->cmd[0])
// 			{
// 				current->next = create_cmd_node();
// 				current = current->next;
// 			}
// 			add_arg(current, value);
// 		}
// 		else if (token == IREDIR)
// 		{
// 			tokens = tokens->next;
// 			if (tokens)
// 				current->infile = ft_strdup(tokens->content);
// 			else
// 				syntax_error("Expected filename after '<'", minishell);
// 		}
// 		else if (token == OREDIR || token == APPEND)
// 		{
// 			if (token == APPEND)
// 				current->append = 1;
// 			tokens = tokens->next;
// 			if (tokens)
// 				current->outfile = ft_strdup(tokens->content);
// 			else
// 				syntax_error("Expected filename after '>' or '>>'", minishell);
// 		}
// 		else if (token == PIPE)
// 		{
// 			if (current->cmd && current->cmd[0])
// 			{
// 				current->next = create_cmd_node();
// 				current = current->next;
// 			}
// 		}
// 		tokens = tokens->next;
// 	}
// 	return (head);
// }
