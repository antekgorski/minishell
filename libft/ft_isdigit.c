/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:07:50 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:13:25 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is a digit.
 *
 * The function tests whether the input character `c` is a decimal digit 
 * (i.e., a character between '0' and '9').
 *
 * @param c The character to be checked, passed as an integer. The value of 
 *          `c` should be representable as an unsigned char or EOF.
 * 
 * @return Non-zero (true) if `c` is a digit, and 0 (false) otherwise.
 * 
 * @note This function behaves similarly to the standard `isdigit` function 
 *       in the C library, checking if the value is between '0' and '9'.
 */
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	else
		return (0);
}
