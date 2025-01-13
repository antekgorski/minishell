/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:06:51 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/13 11:06:37 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

// dodać czyszenie cmd!
static t_cmd	*create_cmd_node(void)
{
	t_cmd	*new_cmd;

	new_cmd = malloc(sizeof(t_cmd));
	if (!new_cmd)
		ft_panic("malloc failed", 1);
	new_cmd->cmd = NULL;
	new_cmd->infile = NULL;
	new_cmd->outfile = NULL;
	new_cmd->append = 0;
	new_cmd->next = NULL;
	return (new_cmd);
}

static void	add_arg(t_cmd *cmd, char *arg)
{
	int	i;

	i = 0;
	while (cmd->cmd && cmd->cmd[i])
		i++;
	cmd->cmd = realloc(cmd->cmd, sizeof(char *) * (i + 2));
	if (!cmd->cmd)
		ft_panic("realloc failed", 1);
	cmd->cmd[i] = ft_strdup(arg);
	cmd->cmd[i + 1] = NULL;
}

t_cmd	*parse_tokens(t_minishell *minishell)
{
	t_cmd	*head;
	t_cmd	*current;
	t_list	*tokens;
	t_token	token;
	char	*value;

	head = NULL;
	current = NULL;
	tokens = minishell->token_list;
	while (tokens)
	{
		token = *((t_token *)tokens->content);
		value = tokens->content;
		if (token == CMD)
		{
			if (!head)
			{
				head = create_cmd_node();
				current = head;
			}
			else if (current->cmd && current->cmd[0])
			{
				current->next = create_cmd_node();
				current = current->next;
			}
			add_arg(current, value);
		}
		else if (token == IREDIR)
		{
			tokens = tokens->next;
			if (tokens)
				current->infile = ft_strdup(tokens->content);
			else
				syntax_error("Expected filename after '<'", minishell);
		}
		else if (token == OREDIR || token == APPEND)
		{
			if (token == APPEND)
				current->append = 1;
			tokens = tokens->next;
			if (tokens)
				current->outfile = ft_strdup(tokens->content);
			else
				syntax_error("Expected filename after '>' or '>>'", minishell);
		}
		else if (token == PIPE)
		{
			if (current->cmd && current->cmd[0])
			{
				current->next = create_cmd_node();
				current = current->next;
			}
		}
		tokens = tokens->next;
	}
	return (head);
}
