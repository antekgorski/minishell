/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:17:29 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:13:14 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is alphabetic.
 *
 * The function tests whether the input character `c` is an alphabetic letter,
 * either lowercase (`a-z`) or uppercase (`A-Z`).
 *
 * @param c The character to be checked, passed as an integer. The value of
 *          `c` must be representable as an unsigned char or be equal to EOF.
 *
 * @return Non-zero (true) if `c` is an alphabetic character,
 *	and 0 (false) otherwise.
 *
 * @note This function behaves similarly to the standard `isalpha` function
 *       in the C library, checking for both uppercase and lowercase letters.
 *
 * @warning Ensure that the value of `c` is within the valid range of
 *          `unsigned char` or equal to EOF to avoid undefined behavior.
 */
int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1024);
	else
		return (0);
}
