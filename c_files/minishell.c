/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:33:16 by agorski           #+#    #+#             */
/*   Updated: 2024/12/05 10:58:39 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	main(int argc, char **argv)
{
	char	*line;
	t_list	*command_list;
//signal handler --
// pirnt a prompt +
// Read a line +
// Parse --
// 	bulid tree representation.--
// Execute -- (repeat)..

	while (1)
	{
		line = readline(PROMPT);// Wyświetla prompt "antpaw$" i czeka na wprowadzenie danych
		if (!line)               // Sprawdza, czy użytkownik wprowadził EOF
			break ;
		if (*line) // Sprawdza, czy linia nie jest pusta
		{
			add_history(line); // Dodaje linię do historii
			command_list = parse(line, command_list); // Wywołuje funkcję parse, która wypisuje na ekranie podzieloną linię
			while(command_list)
			{
				printf("%s\n", command_list->command);
				command_list = command_list->next;
			}	
		}
		free(line); // Zwalnia pamięć przydzieloną przez readline
	}
}
// główna funkcja programu, w której wywoływana jest funkcja readline,
// która zwraca wskaźnik na bufor z wczytaną linią
// jeżeli wczytana linia nie jest pusta, to dodajemy ją do historii
// i wypisujemy na ekranie
