/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:44:48 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/18 13:15:14 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static size_t	ft_countwords(const char *s, char c)
{
	size_t	i;

	i = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

static char	*word_copy(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	ft_initiate_vars(size_t *i, int *j, int *index)
{
	*i = 0;
	*j = 0;
	*index = -1;
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		index;
	char	**word;
	size_t	i;

	ft_initiate_vars(&i, &j, &index);
	word = (char **)ft_calloc((ft_countwords(s, c) + 1), sizeof(char *));
	if (!word)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			word[j] = word_copy(s, index, i);
			if (word[j] == NULL)
				return (ft_free(word, j));
			index = -1;
			j++;
		}
		i++;
	}
	word[j] = 0;
	return (word);
}

/*
#include <stdio.h>

int	main(void)
{
	const char	*test_cases[] = {"This is a string", "This, is, a, string", "",
			"  ", NULL};
	for (int i = 0; test_cases[i]; i++)
	{
		printf("Test case %d: Count = %zu\n", i + 1,
			ft_countwords(test_cases[i], ' '));
	}
	return (0);
}
*/