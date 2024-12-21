/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:05:57 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:17:29 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds a new element to the beginning of a linked list.
 *
 * The function adds the element pointed to by `new` at the front of the 
 * linked list pointed to by `lst`. If the list is empty, the new 
 * element becomes the first element of the list.
 *
 * @param lst A pointer to a pointer to the first element of the list. 
 *            This allows modification of the head of the list.
 * @param new A pointer to the new element to be added to the list.
 * 
 * @return None.
 * 
 * @note This function checks if both `lst` and `new` are not `NULL` 
 *       before proceeding to add the new element.
 * 
 * @warning If either `lst` or `new` is `NULL`, the function does nothing 
 *          and will not modify the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
