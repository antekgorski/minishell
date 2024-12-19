/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2024/12/19 10:51:45 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int ft_cd(char **args)
{
    if  (!args[1])
    {
        write(2, "cd: missing argument\n", 22);
        return (1);
    }

    if (chdir(args[1]) != 0)
    {
        perror("cd");
        return (1);
    }

    return (0);
}