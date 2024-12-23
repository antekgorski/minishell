/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:47:54 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:17:40 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

/**
 * @brief Creates a new linked list element.
 *
 * The function allocates memory for a new linked list element, initializes 
 * its content with the provided `content`, and sets its `next` pointer to 
 * `NULL`. If memory allocation fails, it returns `NULL`.
 *
 * @param content A pointer to the content to be assigned to the new element.
 * 
 * @return A pointer to the newly created linked list element, or `NULL` 
 *         if memory allocation fails.
 * 
 * @note The caller is responsible for managing the memory of the `content` 
 *       provided. The function does not make a copy of the content.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*lstnew;

	lstnew = malloc(sizeof(t_list));
	if (lstnew == NULL)
		return (NULL);
	lstnew->content = content;
	lstnew->next = NULL;
	return (lstnew);
}

// int main()
// {
// 	t_list *new = ft_lstnew("test");
// 	printf("%s\n", (char *)new->content);
// 	return (0);
// }