/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:07:58 by agorski           #+#    #+#             */
/*   Updated: 2024/12/21 23:35:05 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Splits a string into an array of words based on a delimiter.
 *
 * The function takes a null-terminated string `s` and splits it into
 * words, using the character `c` as the delimiter. The resulting
 * words are stored in a dynamically allocated array of strings.
 * The array is null-terminated.
 *
 * @param s The string to be split into words. It should be null-terminated.
 * @param c The delimiter character used to separate words in the string.
 *
 * @return A pointer to an array of strings (words), or NULL if memory
 *         allocation fails or if `s` is NULL. The last element of the
 *         array is NULL to indicate the end of the words.
 *
 * @note This function uses helper functions for counting words and
 *       managing memory. Memory allocated for the array and its contents
 *       should be freed by the caller after use.
 */
static void	ft_initvar(size_t *index, int *word_index, int *start_of_word)
{
	*index = 0;
	*word_index = 0;
	*start_of_word = -1;
}

static void	*ft_free_words(char **words, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(words[i++]);
	free(words);
	return (NULL);
}

static char	*ft_fill_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

static int	ft_word_count(const char *str, char c)
{
	int	count;
	int	trigger;

	count = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (count);
}

/**
 * @attention MALOC
 * @brief Splits a string into an array of words based on a delimiter.
 * @param s The string to be split into words. It should be null-terminated.
 * @param c The delimiter character used to separate words in the string.
 * @return A pointer to an array of strings (words), or NULL if memory
 */
char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	index;
	int		word_index;
	int		start_of_word;

	ft_initvar(&index, &word_index, &start_of_word);
	result = ft_calloc((ft_word_count(s, c) + 1), sizeof(char *));
	if (!result)
		return (NULL);
	while (index <= ft_strlen(s))
	{
		if (s[index] != c && start_of_word < 0)
			start_of_word = index;
		else if ((s[index] == c || index == ft_strlen(s)) && start_of_word >= 0)
		{
			result[word_index] = ft_fill_word(s, start_of_word, index);
			if (!(result[word_index]))
				return (ft_free_words(result, word_index));
			start_of_word = -1;
			word_index++;
		}
		index++;
	}
	return (result);
}
