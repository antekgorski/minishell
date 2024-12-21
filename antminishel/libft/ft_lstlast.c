/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 00:53:08 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:17:36 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the last element of a linked list.
 *
 * The function traverses the linked list pointed to by `lst` and returns 
 * a pointer to the last element. If the list is empty (i.e., `lst` is `NULL`), 
 * it returns `NULL`.
 *
 * @param lst A pointer to the first element of the linked list. 
 *            This pointer must not be `NULL` unless the list is empty.
 * 
 * @return A pointer to the last element of the list, or `NULL` if the list 
 *         is empty.
 * 
 * @note The function traverses the entire list to find the last element.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
