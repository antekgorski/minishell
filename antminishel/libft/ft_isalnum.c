/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:29:19 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:13:10 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is alphanumeric.
 *
 * The function tests whether the input character `c` is alphanumeric,
 * meaning it is either an alphabetic letter (`a-z`, `A-Z`) or a digit (`0-9`).
 *
 * @param c The character to be checked, passed as an integer. The value of
 *          `c` must be representable as an unsigned char or be equal to EOF.
 *
 * @return Non-zero (true) if `c` is alphanumeric, and 0 (false) otherwise.
 *
 * @note This function behaves similarly to the standard `isalnum` function
 *       in the C library,
 *	leveraging the helper functions `ft_isalpha` and `ft_isdigit`.
 *
 * @warning Ensure that the value of `c` is within the valid range of
 *          `unsigned char` or equal to EOF to avoid undefined behavior.
 */
int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (8);
	else
		return (0);
}
