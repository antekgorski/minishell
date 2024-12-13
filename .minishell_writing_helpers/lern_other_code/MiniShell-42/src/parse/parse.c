/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:57:24 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/08 18:52:44 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*ft_check_and_comb(t_content *minishell)
{
	if (minishell->parse_error.type)
		return (NULL);
	if (minishell->free_token->type == T_PIPE)
		return (ft_parse_err(E_SYNTAXERR, minishell), NULL);
	return (ft_get_text_command(minishell));
}

t_node	*ft_start_parse(t_content *minishell)
{
	t_node	*left;
	t_node	*right;

	if (!minishell->free_token || minishell->parse_error.type)
		return (NULL);
	left = ft_check_and_comb(minishell);
	if (!left)
		return (NULL);
	while (check_for_pipe_and_token(minishell))
	{
		ft_get_next_token(minishell);
		if (!minishell->free_token)
		{
			return (ft_parse_err(E_SYNTAXERR, minishell), left);
		}
		right = ft_start_parse(minishell);
		if (!right)
			return (left);
		left = ft_combine(left, E_PIPE, right, minishell);
		if (!left)
			return (NULL);
	}
	return (left);
}

t_node	*ft_combine(t_node *left, t_node_type operator, t_node *right,
		t_content *minishell)
{
	t_node	*node;

	if (minishell->parse_error.type)
		return (NULL);
	node = get_new_node(operator);
	if (!node)
		return (ft_parse_err(E_MEMORY, minishell), NULL);
	node->left = left;
	node->right = right;
	return (node);
}

t_node	*ft_parse(t_content *minishell)
{
	t_node	*parsed;

	minishell->free_token = minishell->tokens;
	parsed = ft_start_parse(minishell);
	if (minishell->free_token)
	{
		write(1, "ts", 2);
		return (ft_parse_err(E_SYNTAXERR, minishell), parsed);
	}
	return (parsed);
}
