/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:12:10 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:12:53 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts a string to an integer.
 *
 * The function takes a string (`nptr`) and converts it into an integer, 
 * interpreting leading whitespace and optional '+' or '-' signs.
 * It stops conversion when a non-numeric character is encountered.
 *
 * @param nptr The string to be converted to an integer.
 * 
 * @return The integer representation of the string. If the string is empty 
 *         or does not start with a valid numeric character, the function 
 *         returns 0.
 * 
 * @note The function handles optional leading whitespaces and signs 
 *       ('+' or '-'). It only processes digits and stops conversion at 
 *       the first non-digit character.
 * 
 * @warning The function does not handle overflow or underflow cases. 
 *          If the input value exceeds the range of `int`, the behavior 
 *          is undefined.
 */
int	ft_atoi(const char *nptr)
{
	int	sign;
	int	num;

	num = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		num *= 10;
		num += (*nptr - 48);
		nptr++;
	}
	num *= sign;
	return (num);
}
