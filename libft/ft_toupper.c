/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:23:55 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:23:05 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts a lowercase letter to uppercase.
 *
 * This function takes an integer `c` representing a character 
 * and converts it to its uppercase equivalent if it is a 
 * lowercase letter. If `c` is not a lowercase letter, it 
 * returns `c` unchanged.
 *
 * @param c The character to be converted, represented as an 
 *          integer (typically a character from the ASCII set).
 *
 * @return The uppercase equivalent of the character if it 
 *         is a lowercase letter; otherwise, it returns the 
 *         original character.
 *
 * @note If `c` is not within the ASCII range for lowercase letters, 
 *       the function will return the character unchanged.
 */
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
