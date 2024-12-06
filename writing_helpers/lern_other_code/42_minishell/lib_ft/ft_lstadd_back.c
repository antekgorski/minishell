/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:31:26 by ssuchane          #+#    #+#             */
/*   Updated: 2024/10/03 19:10:14 by ssuchane         ###   ########.fr       */
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
	t_list	*ptr;

	ptr = *lst;
	if (!ptr)
		*lst = new;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}
