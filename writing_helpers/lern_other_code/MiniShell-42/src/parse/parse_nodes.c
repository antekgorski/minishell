/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:41:22 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/02 13:17:12 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*get_new_node(t_node_type type)
{
	t_node	*new;

	new = ft_calloc(1, sizeof(t_node));
	if (!new)
		return (NULL);
	new->type = type;
	return (new);
}

t_io_node	*ft_add_io_node(t_token_type type, char *value)
{
	t_io_node	*new;

	new = ft_calloc(1, sizeof(t_io_node));
	if (!new)
		return (NULL);
	new->type = ft_get_io_type(type);
	new->value = ft_strdup(value);
	if (!new->value)
		return (free(new), NULL);
	return (new);
}

void	ft_connect_io_node(t_io_node **nodes, t_io_node *new)
{
	t_io_node	*curr_node;

	if (!*nodes)
	{
		*nodes = new;
		return ;
	}
	curr_node = *nodes;
	while (curr_node && curr_node->next)
		curr_node = curr_node->next;
	curr_node->next = new;
}
