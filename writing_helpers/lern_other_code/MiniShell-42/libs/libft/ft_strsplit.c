/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:56:11 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/18 13:38:31 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char delimiter)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str == delimiter)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static char	*allocate_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i++] = str[start++];
	}
	word[i] = '\0';
	return (word);
}

static void	process_word(const char *str, t_split_data *data, char **result,
		char delimiter)
{
	int	in_word;

	in_word = 0;
	while (str[data->i] != '\0')
	{
		if (str[data->i] == delimiter)
		{
			if (in_word)
			{
				in_word = 0;
				result[data->word_index++] = allocate_word(str,
						data->word_start, data->i);
			}
		}
		else if (!in_word)
		{
			in_word = 1;
			data->word_start = data->i;
		}
		data->i++;
	}
	if (in_word)
		result[data->word_index] = allocate_word(str, data->word_start,
				data->i);
}

static void	split_words(const char *str, char delimiter, char **result)
{
	t_split_data	data;

	data.i = 0;
	data.word_index = 0;
	data.word_start = 0;
	process_word(str, &data, result, delimiter);
}

char	**ft_strsplit(const char *str, char delimiter)
{
	int		words_count;
	char	**result;

	if (!str)
		return (NULL);
	words_count = count_words(str, delimiter);
	result = (char **)malloc((words_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	split_words(str, delimiter, result);
	result[words_count] = NULL;
	return (result);
}
