/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:33:16 by agorski           #+#    #+#             */
/*   Updated: 2024/11/13 18:00:34 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	main(int argc, char **argv)
{
	char	*line;

	while (1)
	{
		line = readline("antpaw$");
		// Wyświetla prompt "antpaw$" i czeka na wprowadzenie danych
		if (!line) // Sprawdza, czy użytkownik wprowadził EOF
			break ;
		if (*line) // Sprawdza, czy linia nie jest pusta
		{
			add_history(line);    // Dodaje linię do historii
			printf("%s\n", line); // Wyświetla wprowadzone dane
		}
		free(line); // Zwalnia pamięć przydzieloną przez readline
	}
}
// główna funkcja programu, w której wywoływana jest funkcja readline,
// która zwraca wskaźnik na bufor z wczytaną linią
// jeżeli wczytana linia nie jest pusta, to dodajemy ją do historii
// i wypisujemy na ekranie
