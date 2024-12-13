/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 02:54:49 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/02 10:37:51 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strjoin_f(char *s1, char *s2)
{
	char	*joined;
	size_t	total_length;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	total_length = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = ft_calloc(total_length, sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = 0;
	return (free(s1), free(s2), joined);
}

char	*ft_handle_dollar(char *str, int *i, t_content *minishell)
{
	int		start;
	char	*variab;
	char	*env_value;

	(*i)++;
	if (ft_isdigit(str[*i]) || str[*i] == '@')
	{
		(*i)++;
		return (ft_strdup(""));
	}
	else if (str[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(minishell->exit_state));
	}
	else if (!ft_is_valid_var_char(str[*i]))
		return (ft_strdup("$"));
	start = *i;
	while (ft_is_valid_var_char(str[*i]))
		(*i)++;
	variab = ft_substr(str, start, *i - start);
	env_value = ft_get_envlst_val(variab, minishell);
	if (!env_value)
		return (free(variab), ft_strdup(""));
	return (free(variab), ft_strdup(env_value));
}

static char	*ft_handle_singqoute(char *str, int *i)
{
	int	strt;

	strt = *i;
	(*i)++;
	while (str[*i] != '\'')
		(*i)++;
	(*i)++;
	return (ft_substr(str, strt, *i - strt));
}

static char	*ft_handle_expand(char *str, t_content *minishell)
{
	char	*retur;
	int		i;

	retur = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			retur = ft_strjoin_f(retur, ft_handle_singqoute(str, &i));
		else if (str[i] == '"')
			retur = ft_strjoin_f(retur, ft_handle_doubqoute(str, &i,
						minishell));
		else if (str[i] == '$')
			retur = ft_strjoin_f(retur, ft_handle_dollar(str, &i, minishell));
		else
			retur = ft_strjoin_f(retur, ft_normal_string(str, &i));
	}
	return (retur);
}

char	**ft_expand(char *str, t_content *minishell)
{
	char	**expanded;
	int		i;

	i = 0;
	str = ft_handle_expand(str, minishell);
	if (!str)
		return (NULL);
	str = ft_clean_empy_str(str);
	if (!str)
		return (NULL);
	expanded = ft_expander_split(str);
	free(str);
	if (!expanded)
		return (NULL);
	while (expanded[i])
	{
		expanded[i] = ft_strip_quotes(expanded[i]);
		i++;
	}
	return (expanded);
}
