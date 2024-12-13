/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:46:03 by dtoszek           #+#    #+#             */
/*   Updated: 2024/07/16 16:23:52 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_create_add_separator(t_token_type type, char **line,
		t_token **tokens)
{
	t_token	*token;

	token = ft_new_token(NULL, type);
	if (!token)
		return (0);
	ft_token_add_back(tokens, token);
	(*line)++;
	if (type == T_DGREAT || type == T_DLESS)
		(*line)++;
	return (1);
}

void	ft_skip_spaces(char **line)
{
	while (**line && ft_isspace(**line))
		(*line)++;
}

int	ft_is_separator(char *line)
{
	if (*line == ' ' || *line == '\t' || *line == '<' || *line == '>'
		|| *line == '|')
		return (1);
	return (0);
}

int	ft_is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

bool	ft_skip_quotes(char *line, size_t *i)
{
	char	quote;

	quote = line[*i];
	if (ft_strchr(line + *i + 1, quote))
	{
		(*i)++;
		while (line[*i] != quote)
			(*i)++;
		(*i)++;
		return (true);
	}
	return (false);
}
