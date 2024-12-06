/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 23:22:13 by fursini           #+#    #+#             */
/*   Updated: 2024/05/20 17:33:29 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirection(char *str)
{
	if (str[0] == '|')
		return (1);
	else if (str[0] == '>' && str[1] && str[1] == '>')
		return (2);
	else if (str[0] == '>')
		return (1);
	else if (str[0] == '<' && str[1] && str[1] == '<')
		return (2);
	else if (str[0] == '<')
		return (1);
	return (0);
}

bool	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}
