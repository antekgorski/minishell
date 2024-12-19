/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2024/12/19 11:42:32 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int ft_echo(char **args)
{
    int i;
    int newLine;
    
    i = 1;
    newLine = 1;
    if(args[1] && ft_strcmp(args[1], "-n") == 0)
    {
        newLine = 0;
        i++;
    }

    while(args[i])
    {
        printf("%s", args[i]);
        if(args[i + 1])
            printf(" ");
        i++;
    }

    if(newLine)
        printf("\n");
    return (0);
}