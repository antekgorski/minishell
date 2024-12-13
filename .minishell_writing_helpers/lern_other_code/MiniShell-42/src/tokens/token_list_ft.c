/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_ft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:08:03 by dtoszek           #+#    #+#             */
/*   Updated: 2024/12/12 14:57:11 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*ft_new_token(char *str, t_token_type type)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = str;
	token->type = type;
	return (token);
}

void	ft_token_add_back(t_token **tokens, t_token *token)
{
	t_token	*curr_node;

	if (!*tokens)
	{
		*tokens = token;
		return ;
	}
	curr_node = *tokens;
	while (curr_node && curr_node->next)
		curr_node = curr_node->next;
	curr_node->next = token;
}

void	ft_list_clear(t_token **tokens)
{
	t_token	*curr_node;
	t_token	*next;

	curr_node = *tokens;
	if (!curr_node)
		return ;
	while (curr_node)
	{
		free(curr_node->value);
		next = curr_node->next;
		free(curr_node);
		curr_node = next;
	}
	*tokens = NULL;
}
