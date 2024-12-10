/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:23:41 by agorski           #+#    #+#             */
/*   Updated: 2024/12/10 18:34:05 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	**parse(void *line)
{
	char	**tab_pipe;
	int		i;
	
	//check_quote((char *)line);
	
	tab_pipe = ft_split((char *)line, '|');
	
	return (tab_pipe);
}
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