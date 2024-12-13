/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:11:47 by sehosaf           #+#    #+#             */
/*   Updated: 2024/07/17 10:13:05 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	count_tokens(char *line);
static char	*get_end(char *line);
static char	*search_token_end(char *start);

/*
	Similar to `ft_split` function but with original split logic
	For more details check `char *search_token_end(char *start)`
*/
char	**split_line(char *line)
{
	int		w;
	char	**res;
	char	*end;
	int		n_tokens;

	n_tokens = count_tokens(line);
	if (!n_tokens)
		return (NULL);
	res = malloc((n_tokens + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	w = 0;
	while (*line)
	{
		while (ft_isspace(*line))
			line++;
		if (!*line)
			break ;
		end = get_end(line);
		res[w++] = ft_substr(line, 0, end - line);
		line = end;
	}
	res[w] = NULL;
	return (res);
}

static int	count_tokens(char *line)
{
	int	counter;

	counter = 0;
	while (*line)
	{
		while (ft_isspace(*line))
			line++;
		if (!*line)
			break ;
		line = get_end(line);
		counter++;
	}
	return (counter);
}

static char	*get_end(char *line)
{
	char	*end;

	if (*line == '|')
	{
		end = line + 1;
		if (line[1] == '|')
			end = line + 2;
	}
	else if (!ft_memcmp(line, "&&", 2))
		end = line + 2;
	else
		end = search_token_end(line);
	return (end);
}

/*
	Searches for token end.
	Returns character next after token end.
	Designed to cope with cases like:
	- 'file name'.txt
	- file."$EXTENSION"
	- ls|grep
*/
static char	*search_token_end(char *start)
{
	char	*end;

	if (*start == '\'')
	{
		end = ft_strchr(start + 1, '\'');
		if (end)
			return (search_token_end(end + 1));
		return (ft_strchr(start + 1, '\0'));
	}
	if (*start == '"')
	{
		end = ft_strchr(start + 1, '"');
		if (end)
			return (search_token_end(end + 1));
		return (ft_strchr(start + 1, '\0'));
	}
	if (ft_isspace(*start) || *start == '\0' || *start == '|'
		|| !ft_memcmp(start, "&&", 2))
		return (start);
	return (search_token_end(start + 1));
}
