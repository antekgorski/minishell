/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 03:18:16 by fursini           #+#    #+#             */
/*   Updated: 2024/05/20 17:33:24 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_quotes(t_minishell *shell)
{
	t_token	*token;
	char	*new;
	int		i;

	new = NULL;
	token = shell->token_list;
	while (token)
	{
		i = 0;
		while (token->str[i])
		{
			if (token->str[i] == '"' || token->str[i] == '\'')
			{
				i += handle_quotes(token->str + i, shell) - 2;
				token->str = remove_quote(token->str, new);
			}
			i++;
		}
		token = token->next;
	}
}

void	remove_empty_tokens(t_minishell *shell)
{
	t_token	*tmp;

	tmp = shell->token_list;
	while (tmp)
	{
		if (ft_strcmp(tmp->str, "") == 0)
			token_remove(shell, tmp);
		tmp = tmp->next;
	}
}

void	token_remove(t_minishell *shell, t_token *token)
{
	t_token	*tmp;

	tmp = token;
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	if (tmp == shell->token_list)
		shell->token_list = tmp->next;
	check_free(tmp->str);
	check_free(tmp);
}

char	*remove_quote(char *str, char *new)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_calloc(ft_strlen(str) - 1, sizeof(char));
	while (str[i])
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] && str[i] != '"')
				new[j++] = str[i++];
		}
		else if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				new[j++] = str[i++];
		}
		else
			new[j++] = str[i++];
	}
	check_free(str);
	return (new);
}
