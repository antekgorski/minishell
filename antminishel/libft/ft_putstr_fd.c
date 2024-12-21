/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:34:58 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:20:50 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @brief Writes a string to the specified file descriptor.
 *
 * The function outputs the string `s` to the file descriptor `fd`. 
 * It sends each character of the string individually until the null 
 * terminator is reached.
 *
 * @param s A pointer to the null-terminated string to be written.
 * @param fd The file descriptor to which the string will be written. 
 *           Common values include 1 for standard output and 2 for 
 *           standard error.
 * 
 * @note The function does not perform error checking on the write operations. 
 *       If the write fails, the behavior is not defined. Additionally, if 
 *       `s` is `NULL`, the behavior is also not defined.
 */
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}
