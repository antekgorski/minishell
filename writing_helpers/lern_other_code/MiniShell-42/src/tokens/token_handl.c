/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:38:27 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/02 11:40:30 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_handle_separator(char **line, t_token **tokens)
{
	if (!ft_strncmp(*line, "<<", 2))
		return (ft_create_add_separator(T_DLESS, line, tokens));
	else if (!ft_strncmp(*line, ">>", 2))
		return (ft_create_add_separator(T_DGREAT, line, tokens));
	else if (!ft_strncmp(*line, "<", 1))
		return (ft_create_add_separator(T_LESS, line, tokens));
	else if (!ft_strncmp(*line, ">", 1))
		return (ft_create_add_separator(T_GREAT, line, tokens));
	else
		return (ft_create_add_separator(T_PIPE, line, tokens));
}

static void	ft_quote_err(char c, t_content *minishell)
{
	ft_putstr_fd("minishell: unexpected EOF while looking for matching '", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("'\n", 2);
	minishell->exit_state = 258;
}

static int	ft_handle_identifier(char **line, t_token **tokens,
			t_content *minishell)
{
	char	*tmp_line;
	char	*value;
	t_token	*token;
	size_t	i;

	tmp_line = *line;
	i = 0;
	while (tmp_line[i] && !ft_is_separator(tmp_line + i))
	{
		if (ft_is_quote(tmp_line[i]))
		{
			if (!ft_skip_quotes(tmp_line, &i))
				return (ft_quote_err(tmp_line[i], minishell), 0);
		}
		else
			i++;
	}
	value = ft_substr(tmp_line, 0, i);
	if (!value)
		return (0);
	token = ft_new_token(value, T_TEXT);
	if (!token)
		return (free(value), 0);
	*line += i;
	return (ft_token_add_back(tokens, token), 1);
}

t_token	*ft_tokens_handle(char *line, t_content *minishell)
{
	t_token	*tokens;
	int		error;

	error = 0;
	tokens = NULL;
	while (*line)
	{
		if (error)
		{
			return (ft_list_clear(&tokens), NULL);
		}
		if (ft_isspace(*line))
			ft_skip_spaces(&line);
		else if (!ft_strncmp(line, "<", 1) || !ft_strncmp(line, ">", 1)
			|| !ft_strncmp(line, "|", 1))
			error = (!ft_handle_separator(&line, &tokens));
		else
			error = (!ft_handle_identifier(&line, &tokens, minishell));
	}
	return (tokens);
}
