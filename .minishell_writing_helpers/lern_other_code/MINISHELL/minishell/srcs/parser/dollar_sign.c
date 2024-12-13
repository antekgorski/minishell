/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:03:50 by fursini           #+#    #+#             */
/*   Updated: 2024/05/20 17:33:18 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_dollar(t_minishell *shell)
{
	t_token	*tmp;

	tmp = shell->token_list;
	while (tmp)
	{
		if (check_heredoc_single_quote(tmp))
		{
			tmp = tmp->next;
			continue ;
		}
		question_mark(shell, tmp);
		get_dollar_value(tmp, shell);
		tmp = tmp->next;
	}
}

bool	check_heredoc_single_quote(t_token *token)
{
	if (token->prev && token->prev->type == HEREDOC)
		return (true);
	if (token->str && token->str[0] && token->str[0] == '\'')
		return (true);
	return (false);
}

char	*get_env_value(char *key, t_minishell *shell)
{
	t_token	*tmp;
	char	*key_tmp;

	tmp = shell->env_list;
	if (key[0] == '?')
		return (ft_itoa(g_exit_status));
	while (tmp)
	{
		key_tmp = get_key_value(tmp->str);
		if (strcmp(key, key_tmp) == 0)
		{
			check_free(key_tmp);
			return (ft_strdup(tmp->str + ft_strlen(key) + 1));
		}
		check_free(key_tmp);
		tmp = tmp->next;
	}
	return (ft_strdup(""));
}

char	*get_key(char *str)
{
	char	*key;
	int		i;

	i = 0;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_' || str[i] == '?'))
	{
		i++;
		if (str[i] == '?')
			break ;
	}
	key = ft_substr(str, 0, i);
	return (key);
}

void	get_dollar_value(t_token *token, t_minishell *shell)
{
	char	*value;
	char	*tmp;
	char	*new;
	char	*key;
	int		i;

	i = -1;
	while (token->str[++i])
	{
		if (token->str[i] == '\'')
			i += handle_quotes(token->str, shell);
		if (token->str[i] == '$' && token->str[i + 1]
			&& token->str[i + 1] != '"' && token->str[i + 1] != '$'
			&& token->str[i + 1] != ' ')
		{
			tmp = ft_substr(token->str, 0, i);
			key = get_key(token->str + i + 1);
			value = get_env_value(key, shell);
			new = join_str(tmp, value, token->str + i + ft_strlen(key) + 1);
			check_free_4(tmp, value, key, token->str);
			token->str = ft_strdup(new);
			check_free(new);
			i = -1;
		}
	}
}
