/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeneizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:05:29 by agorski           #+#    #+#             */
/*   Updated: 2024/12/19 20:21:16 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_token(t_token token, t_minishell *minishell)
{
	t_list	*new_node;
	t_token	*new_token;

	new_token = ft_calloc(1, sizeof(t_token));
	if (!new_token)
		ft_panic("Malloc failed", 1);
	*new_token = token;
	new_node = ft_lstnew(new_token);
	if (!new_node)
		ft_panic("Malloc failed", 1);
	ft_lstadd_back(&minishell->token_list, new_node);
}
