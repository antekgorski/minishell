/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:39:21 by dtoszek           #+#    #+#             */
/*   Updated: 2024/07/08 15:17:38 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*curr;

	if (!lst || !*lst || !del)
		return ;
	curr = *lst;
	next = curr -> next;
	while (curr && next)
	{
		del(curr -> content);
		free(curr);
		curr = next;
		next = curr -> next;
	}
	del(curr -> content);
	free(curr);
	*lst = NULL;
}
