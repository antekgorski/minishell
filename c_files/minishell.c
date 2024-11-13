/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:33:16 by agorski           #+#    #+#             */
/*   Updated: 2024/11/13 15:14:48 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int main(int argc, char **argv)
{
    while (1)
    {
        char *line;
        line = readline("minishell$ ");
        if (!line)
            break;
        if (*line)
            add_history(line);
        printf("%s\n", line);
        free(line);
    }
}
//główna funkcja programu, w której wywoływana jest funkcja readline,
//która zwraca wskaźnik na bufor z wczytaną linią
//jeżeli wczytana linia nie jest pusta, to dodajemy ją do historii
//i wypisujemy na ekranie

