/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tokens_per_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:13:37 by sehosaf           #+#    #+#             */
/*   Updated: 2024/07/17 10:15:28 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	fill_w_tokens(t_pipeline *start, char **tokens, int first, int cur);

/*
	Creates node for each command and fills it args with relevant tokens.
*/
void	split_tokens_per_command(t_pipeline *start, char **tokens)
{
	int	first;
	int	curr;

	first = 0;
	curr = 0;
	while (tokens[curr])
	{
		if (!ft_memcmp(tokens[curr], "|", 2)
			|| !ft_memcmp(tokens[curr], "||", 3)
			|| !ft_memcmp(tokens[curr], "&&", 3))
		{
			fill_w_tokens(start, tokens, first, curr);
			start->next = create_default_pipeline_node();
			start = start->next;
			first = curr;
		}
		curr++;
	}
	fill_w_tokens(start, tokens, first, curr);
}

static void	fill_w_tokens(t_pipeline *start, char **tokens, int first, int cur)
{
	int	i;

	start->cmd.args = malloc((cur - first + 1) * sizeof(char *));
	if (!start->cmd.args)
		return ;
	i = 0;
	while (i < cur - first)
	{
		start->cmd.args[i] = ft_strdup(tokens[first + i]);
		i++;
	}
	start->cmd.args[cur - first] = NULL;
}
