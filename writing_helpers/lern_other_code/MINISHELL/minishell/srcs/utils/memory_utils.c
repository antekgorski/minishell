/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:59:52 by fursini           #+#    #+#             */
/*   Updated: 2024/05/25 13:23:15 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Frees the memory pointed to by ptr and sets ptr to NULL.
 * 
 * @param ptr Pointer to the memory to be freed.
 */
void	check_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

/**
 * @brief Frees the memory pointed to by four pointers and sets them to NULL.
 * 
 * @param ptr1 Pointer to the first memory block to be freed.
 * @param ptr2 Pointer to the second memory block to be freed.
 * @param ptr3 Pointer to the third memory block to be freed.
 * @param ptr4 Pointer to the fourth memory block to be freed.
 */
void	check_free_4(char *ptr1, char *ptr2, char *ptr3, char *ptr4)
{
	check_free(ptr1);
	check_free(ptr2);
	check_free(ptr3);
	check_free(ptr4);
}

/**
 * @brief Frees a matrix of characters.
 * 
 * @param matrix Pointer to the first element of the matrix to be freed.
 */
void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		check_free(matrix[i]);
		i++;
	}
	check_free(matrix);
}
