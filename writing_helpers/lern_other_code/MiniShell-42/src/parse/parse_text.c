/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:51:21 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/08 13:28:53 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_get_io_list(t_io_node **io_node, t_content *minishell)
{
	t_token_type	redirector_type;
	t_io_node		*tmp_node;

	if (minishell->error)
		return (false);
	while (minishell->free_token
		&& ft_is_redirector(minishell->free_token->type))
	{
		redirector_type = minishell->free_token->type;
		ft_get_next_token(minishell);
		if (!minishell->free_token)
			return (0);
		if (minishell->free_token->type != T_TEXT)
			return (0);
		tmp_node = ft_add_io_node(redirector_type,
				minishell->free_token->value);
		if (!tmp_node)
			return (0);
		ft_connect_io_node(io_node, tmp_node);
		ft_get_next_token(minishell);
	}
	return (1);
}

static int	ft_join_args(char **args, t_content *minishell)
{
	char	*to_free;

	if (minishell->error)
		return (0);
	if (!*args)
		*args = ft_strdup("");
	if (!*args)
		return (0);
	while (minishell->free_token
		&& minishell->free_token->type == T_TEXT)
	{
		to_free = *args;
		*args = ft_strjoin_with(*args, minishell->free_token->value, ' ');
		if (!*args)
			return (free(to_free), 0);
		free(to_free);
		ft_get_next_token(minishell);
	}
	return (1);
}

t_node	*ft_get_text_command(t_content	*minishell)
{
	t_node	*node;

	if (minishell->parse_error.type)
		return (NULL);
	node = get_new_node(E_COMMAND);
	if (!node)
		return (ft_parse_err(E_MEMORY, minishell), NULL);
	while (minishell->free_token && (minishell->free_token->type
			== T_TEXT || ft_is_redirector(minishell->free_token->type)))
	{
		if (minishell->free_token->type == T_TEXT)
		{
			if (!ft_join_args(&(node->args), minishell))
			{
				ft_clear_cmd_node(node);
				return (ft_parse_err(E_MEMORY, minishell), NULL);
			}
		}
		else if (ft_is_redirector(minishell->free_token->type))
		{
			if (!ft_get_io_list(&(node->io_node), minishell))
				return (free(node->args), free(node), NULL);
		}
	}
	return (node);
}
