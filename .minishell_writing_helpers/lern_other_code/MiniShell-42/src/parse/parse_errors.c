/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:57:44 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/08 18:53:07 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_parse_err(t_parse_err type, t_content *minishell)
{
	minishell->parse_error.type = type;
}

void	ft_ex_parse_err(t_content *minishell)
{
	t_parse_err		type;
	t_token_type	token_type;
	char			**types;

	types = (char *[]){"T_TEXT", "<", ">", "<<", ">>",
		"|", "NONE"};
	type = minishell->parse_error.type;
	(void)token_type;
	(void)types;
	if (type)
	{
		if (type == E_SYNTAXERR)
		{
			if (!minishell->free_token)
				token_type = T_NONE;
			else
				token_type = minishell->free_token->type;
			ft_putstr_fd("minishell: syntax error near unexpected token '", 2);
			ft_putstr_fd(types[token_type], 2);
			ft_putstr_fd("'\n", 2);
			minishell->exit_state = 258;
		}
		ft_clear_parse(&minishell->parsed, minishell);
		ft_bzero(&minishell->parse_error, sizeof(t_parse_error));
	}
}
