/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:36:17 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 14:23:01 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts an uppercase letter to lowercase.
 *
 * This function takes an integer `c` representing a character 
 * and converts it to its lowercase equivalent if it is an 
 * uppercase letter. If `c` is not an uppercase letter, it 
 * returns `c` unchanged.
 *
 * @param c The character to be converted, represented as an 
 *          integer (typically a character from the ASCII set).
 *
 * @return The lowercase equivalent of the character if it 
 *         is an uppercase letter; otherwise, it returns the 
 *         original character.
 *
 * @note If `c` is not within the ASCII range for uppercase letters, 
 *       the function will return the character unchanged.
 */
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}
