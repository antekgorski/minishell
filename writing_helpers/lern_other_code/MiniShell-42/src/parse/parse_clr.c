/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_clr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:22:04 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/08 18:52:24 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_clear_io_list(t_io_node **lst)
{
	t_io_node	*curr_node;
	t_io_node	*next;

	curr_node = *lst;
	if (!curr_node)
		return ;
	while (curr_node)
	{
		free(curr_node->value);
		ft_free_char2(curr_node->expanded_value);
		next = curr_node->next;
		free(curr_node);
		curr_node = next;
	}
	*lst = NULL;
}

void	ft_clear_cmd_node(t_node *node)
{
	if (!node)
		return ;
	ft_clear_io_list(&(node->io_node));
	free(node->args);
	ft_free_char2(node->expand_args);
}

void	ft_recursive_clear_parse(t_node *node)
{
	if (!node)
		return ;
	if (node->type == E_COMMAND)
		ft_clear_cmd_node(node);
	else
	{
		if (node->left)
			ft_recursive_clear_parse(node->left);
		if (node->right)
			ft_recursive_clear_parse(node->right);
	}
	free(node);
}

void	ft_clear_parse(t_node **parse, t_content *minishell)
{
	ft_recursive_clear_parse(*parse);
	*parse = NULL;
	ft_list_clear(&minishell->tokens);
}
