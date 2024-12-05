/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:23:41 by agorski           #+#    #+#             */
/*   Updated: 2024/12/05 10:38:40 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

#include <stdio.h>

t_list	*list_create(char *command, t_list *command_list)
{
	t_list *new;
	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->command = command;
	new->next = NULL;
	return (new);
	
}



t_list	*parse(void *line, t_list *command_list)
{
	char	**tab_line;
	int		i;

	tab_line = ft_split((char *)line, ' ');
	i = 0;
	while (tab_line[i])
	{
		command_list = list_crate(tab_line[i], command_list);
		i++;
	}
	return (0);
}
