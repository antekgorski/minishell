/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 01:12:40 by fursini           #+#    #+#             */
/*   Updated: 2024/05/20 17:33:14 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_str(char *s1, char *s2, char *s3)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = -1;
	new = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1, 1);
	if (!new)
		return (NULL);
	while (s1[++i])
		new[i] = s1[i];
	while (s2[++j])
	{
		new[i] = s2[j];
		i++;
	}
	j = 0;
	while (s3[j])
	{
		new[i] = s3[j];
		i++;
		j++;
	}
	return (new);
}

char	*get_key_value(char *str)
{
	int		i;
	char	*key;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	key = ft_calloc(i + 1, 1);
	if (!key)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '=')
		key[i] = str[i];
	return (key);
}

void	question_mark(t_minishell *shell, t_token *token)
{
	char	*first_part;
	char	*last_part;
	char	*value;
	char	*new;
	int		i;

	i = 0;
	while (token->str[i])
	{
		if (token->str[i] == '\'')
			i += handle_quotes(token->str, shell);
		if (token->str[i] == '$' && token->str[i + 1]
			&& token->str[i + 1] == '?')
		{
			first_part = ft_substr(token->str, 0, i);
			value = ft_itoa(g_exit_status);
			last_part = ft_strdup(token->str + i + 2);
			new = join_str(first_part, value, last_part);
			check_free_4(first_part, value, last_part, token->str);
			token->str = ft_strdup(new);
			check_free(new);
			i = 0;
		}
		i++;
	}
}
