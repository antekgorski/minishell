/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:43:39 by agorski           #+#    #+#             */
/*   Updated: 2024/12/15 22:28:44 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	quote_dcheck(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '\"')
		{
			j = i + 1;
			while (line[j] != '\"')
			{
				if (line[j] == '\0')
					return (1);
				j++;
			}
			i = j + 1;
		}
		else
			i++;
	}
	return (0);
}

static int	quote_scheck(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '\'')
		{
			j = i + 1;
			while (line[j] != '\'')
			{
				if (line[j] == '\0')
					return (1);
				j++;
			}
			i = j + 1;
		}
		else
			i++;
	}
	return (0);
}

void	check_quote(char *line)
{
	if (quote_scheck(line) == 1)
	{
		printf("Unmatched single quote. Please check your input.\n");
		
	}
	if (quote_dcheck(line) == 1)
	{
		printf("Unmatched duble quote. Please check your input.\n");
	}
	else
		return ;
}
