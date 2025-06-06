/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:22:54 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:20:42 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @brief Writes a character to the specified file descriptor.
 *
 * The function writes the character `c` to the file descriptor `fd`. 
 * This allows for output to various streams, such as standard output, 
 * error output, or any other file descriptor.
 *
 * @param c The character to be written.
 * @param fd The file descriptor to which the character will be written. 
 *           Common values include 1 for standard output and 2 for 
 *           standard error.
 * 
 * @note This function does not perform error checking on the write operation. 
 *       If the write fails, the behavior is not defined.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
