/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 00:45:00 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:17:44 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts the number of elements in a linked list.
 *
 * The function traverses the linked list pointed to by `lst` and counts
 * the number of elements it contains. If the list is empty (i.e., `lst` is
 * `NULL`), the function returns 0.
 *
 * @param lst A pointer to the first element of the linked list.
 *            This pointer must not be `NULL` unless the list is empty.
 *
 * @return The number of elements in the linked list, or 0 if the list is empty.
 *
 * @note The function does not modify the linked list;
 * it only counts its elements.
 */
int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
