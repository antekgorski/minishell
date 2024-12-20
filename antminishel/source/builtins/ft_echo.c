/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2024/12/20 17:51:19 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	ft_echo(char **args)
{
	//funkcja musi wypisywac do tokena << >> < > | itd
	//jesli nie ma to wypisuje do stdout
	//inaczej wypisuje do tokena
	//jesli angument nastepny to dolar to ma wypisywac bez spacji!
	int	i;
	int	new_line;

	i = 1;
	new_line = 1;
	if (args[1] && ft_strcmp(args[1], "-n") == 0)
	{
		new_line = 0;
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (new_line)
		printf("\n");
	return (0);
}
