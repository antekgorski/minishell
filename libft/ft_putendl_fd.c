/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:42:08 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:20:45 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @brief Writes a string followed by a newline to the specified file 
 * descriptor.
 *
 * The function outputs the string `s` to the file descriptor `fd`,
 * followed by a newline character. This is useful for printing lines of
 * text with automatic line breaks.
 *
 * @param s A pointer to the null-terminated string to be written.
 * @param fd The file descriptor to which the string and newline will be written.
 *           Common values include 1 for standard output and 2 for
 *           standard error.
 *
 * @note The function does not perform error checking on the write operations.
 *       If the write fails, the behavior is not defined. Additionally, if
 *       `s` is `NULL`, the behavior is also not defined.
 */
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}
