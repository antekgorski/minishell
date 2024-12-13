/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 03:21:14 by dtoszek           #+#    #+#             */
/*   Updated: 2024/07/31 03:56:38 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_is_valid_var_char(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (true);
	return (false);
}

char	*ft_normal_string(char *str, int *i)
{
	int	strt;

	strt = *i;
	while (str[*i] && str[*i] != '\'' && str[*i] != '"' && str[*i] != '$')
		(*i)++;
	return (ft_substr(str, strt, *i - strt));
}

static char	*ft_handle_doublquote_str(char *str, int *i)
{
	int	strt;

	strt = *i;
	while (str[*i] != '"' && str[*i] != '$')
		(*i)++;
	return (ft_substr(str, strt, *i - strt));
}

char	*ft_handle_doubqoute(char *str, int *i, t_content *minishell)
{
	char	*retur;

	retur = ft_strdup("\"");
	(*i)++;
	while (str[*i] != '"')
	{
		if (str[*i] == '$')
			retur = ft_strjoin_f(retur, ft_handle_dollar(str, i, minishell));
		else
			retur = ft_strjoin_f(retur, ft_handle_doublquote_str(str, i));
	}
	(*i)++;
	return (ft_strjoin_f(retur, ft_strdup("\"")));
}
