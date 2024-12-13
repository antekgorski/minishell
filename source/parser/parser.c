/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:23:41 by agorski           #+#    #+#             */
/*   Updated: 2024/12/13 19:30:48 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **write_to_tab(char *line)
{
	int start;
	int end;
	int i;

	start = 0;
	end = 0;
	i = 0;
	
	while(line[i])
	{
		if (line[i] == '\'')
		i += ft_squote(line, &i);
		if (line[i] == '\"')
		i += ft_dquote(line, &i);
		if (line[i] == '$')
		i += ft_dolar(line, &i);
		if (line[i] == '|')
		i += ft_pipe(line, &i);
		if (line[i] == '<')
		i += ft_iredir(line, &i);
		if (line[i] == '>')
		i += ft_oredir(line, &i);
		i++;
	}
}

void	parse(char *line)
{
	char **argv;
	
	check_quote(line);
	argv = write_to_tab(line);
	
}

	// char	**tab_pipe;
	// int		i;
	
	// check_quote((char *)line);
	
	// tab_pipe = ft_split((char *)line, '|');
	
	// return (tab_pipe);


	// i = 0;
	// while (tab_line[i])
	// {
	// 	command_list = list_crate(tab_line[i], command_list);
	// 	i++;
	// }

// #include <stdio.h>

// t_list	*list_create(char *command, t_list *command_list)
// {
// 	t_list *new;
// 	new = malloc(sizeof(t_list));
// 	if (new == NULL)
// 		return (NULL);
// 	new->command = command;
// 	new->next = NULL;
// 	return (new);
	
// }