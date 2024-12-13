/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:07:00 by fursini           #+#    #+#             */
/*   Updated: 2024/05/20 17:33:32 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_quotes(char *str, t_minishell *shell)
{
	int		i;

	i = 0;
	if (str[0] == '\'')
	{
		while (str[++i])
		{
			if (str[i] == '\'')
				return (i);
		}
		unclosed_quote_error(shell);
	}
	else if (str[0] == '"')
	{
		while (str[++i])
		{
			if (str[i] == '"')
				return (i);
		}
		unclosed_quote_error(shell);
	}
	return (i);
}

int	count_tokens(char *str, t_minishell *shell)
{
	int		i;
	int		tokens;

	i = 0;
	tokens = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		else if (str[i] && !ft_isspace(str[i]) && !redirection(str + i))
		{
			tokens++;
			while (str[i] && !ft_isspace(str[i]) && !redirection(str + i))
			{
				if (str[i] == '"' || str[i] == '\'')
					i += handle_quotes(str + i, shell);
				i++;
			}
		}
		else if (redirection(str + i) && tokens++)
			i += redirection(str + i);
	}
	return (tokens);
}

int	token_len(char *str, t_minishell *shell)
{
	int		i;

	i = 0;
	if (redirection(str))
		return (redirection(str));
	while (str[i] && !ft_isspace(str[i]) && !redirection(str + i))
	{
		if (str[i] == '"' || str[i] == '\'')
			i += handle_quotes(str + i, shell);
		i++;
	}
	return (i);
}

char	**tokenizer(char *str, t_minishell *shell)
{
	char	**tokens;
	int		tokens_count;
	int		i;

	i = 0;
	tokens_count = count_tokens(str, shell);
	tokens = ft_calloc(tokens_count + 1, sizeof(char *));
	tokens[tokens_count] = NULL;
	while (i < tokens_count)
	{
		while (*str && ft_isspace(*str))
			str++;
		tokens[i] = ft_substr(str, 0, token_len(str, shell));
		str += token_len(str, shell);
		i++;
	}
	return (tokens);
}
