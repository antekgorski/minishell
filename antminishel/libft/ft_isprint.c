/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:27:42 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:13:28 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is printable.
 *
 * The function tests whether the input character `c` is a printable character,
 * meaning it is a character with a value between 32 and 126 inclusive.
 * This includes letters, digits, punctuation, and space.
 *
 * @param c The character to be checked, passed as an integer. The value of
 *          `c` should be representable as an unsigned char or EOF.
 *
 * @return Non-zero (true) if `c` is a printable character,
 *	and 0 (false) otherwise.
 *
 * @note This function behaves similarly to the standard `isprint` function
 *       in the C library,
 *	which checks for the range of printable ASCII characters.
 */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	else
		return (0);
}
