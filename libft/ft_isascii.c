/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:42:38 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:13:21 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is an ASCII character.
 *
 * The function tests whether the input character `c` is a valid ASCII 
 * character, which is any character with a value between 0 and 127 inclusive.
 *
 * @param c The character to be checked, passed as an integer. The value of 
 *          `c` should be representable as an unsigned char or EOF.
 * 
 * @return Non-zero (true) if `c` is an ASCII character, and 0 (false) otherwise.
 * 
 * @note This function behaves similarly to the standard `isascii` function 
 *       in the C library, checking if the value is within the 7-bit ASCII range.
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
