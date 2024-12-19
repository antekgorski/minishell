/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2024/12/19 13:37:16 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int execute_command(char **args)
{
    if(!args || !args[0])
        return (1);

    if (args[0] && ft_strcmp(args[0], "pwd") == 0)
        return ft_pwd();
    else if (args[0] &&  ft_strcmp(args[0], "echo") == 0)
        return ft_echo(args);
    else if (args[0] && ft_strcmp(args[0], "cd") == 0)
        return ft_cd(args);
    else if (args[0] && ft_strcmp(args[0], "exit") == 0)
        return ft_exit();

    return (1);
}

// int main(void)
// {    
//     printf("TEST ECHO:\n");
//     // char *test1[] = {"echo","-n" , "Siemaneczko" ,NULL};
//     char *test1[] = {"echo", "Siemaneczko" ,NULL};
//     execute_command(test1);

//     printf("TEST PWD:\n");
//     char *test2[] = {"pwd",NULL};
//     execute_command(test2);

//     printf("TEST CD:\n");
//     char *test3[] = {"cd","..",NULL};
//     execute_command(test3);
//     execute_command(test2);

//     printf("TEST EXIT:\n");
//     char *test4[] = {"exit",NULL};
//     execute_command(test4);

//     return 0;
// }
