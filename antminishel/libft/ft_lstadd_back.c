/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 01:01:26 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:17:26 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds a new element to the end of a linked list.
 *
 * The function adds the element pointed to by `new` at the end of the 
 * linked list pointed to by `lst`. If the list is empty, the new 
 * element becomes the first element of the list.
 *
 * @param lst A pointer to a pointer to the first element of the list. 
 *            This allows modification of the head of the list if it is empty.
 * @param new A pointer to the new element to be added to the list.
 * 
 * @return None.
 * 
 * @note This function assumes that `new` is a valid pointer to an 
 *       allocated `t_list` structure. It does not check for memory 
 *       allocation issues.
 * 
 * @warning If `new` is `NULL`, the behavior of this function is 
 *          undefined, as it does not handle the case of adding a 
 *          null element.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
