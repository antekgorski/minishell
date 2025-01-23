// #include "../../headers/minishell.h"

// /**
//  * @brief Parsuje linię poleceń i buduje listę komend.
//  *
//  * @param minishell Struktura minishell zawierająca listę komend.
//  */
// void parse_line(t_minishell *minishell)
// {
//     int i = 0;

//     // Inicjalizacja cmd_list, jeśli nie jest zainicjalizowany
//     if (minishell->cmd_list == NULL)
//         minishell->cmd_list = ft_lstnew_cmd();

//     minishell->lexter_tab = NULL;

//     while (minishell->line[i])
//     {
//         if (ft_strchr(SYMBOLS_D, minishell->line[i]))
//         {
//             if (minishell->line[i] == ' ' || minishell->line[i] == '\t')
//             {
//                 i++;
//                 continue ;
//             }
//             else if (minishell->line[i] == '|')
//             {
//                 // Obsługa potoku
//                 ft_pipe(minishell);
//                 i++;
//             }
//             else if (minishell->line[i] == '<')
//             {
//                 // Obsługa przekierowania wejścia
//                 if (minishell->line[i + 1] == '<')
//                 {
//                     // Heredoc
//                     i += 2;
//                     handle_heredoc_token(minishell, &i);
//                 }
//                 else
//                 {
//                     // Przekierowanie wejścia
//                     i += 1;
//                     handle_input_redirection(minishell, &i);
//                 }
//             }
//             else if (minishell->line[i] == '>')
//             {
//                 // Obsługa przekierowania wyjścia
//                 if (minishell->line[i + 1] == '>')
//                 {
//                     // Przekierowanie append
//                     i += 2;
//                     handle_append_redirection(minishell, &i);
//                 }
//                 else
//                 {
//                     // Przekierowanie wyjścia
//                     i += 1;
//                     handle_output_redirection(minishell, &i);
//                 }
//             }
//         }
//         else
//         {
//             // Przetwarzanie komendy
//             i += ft_comend(&minishell->line[i], minishell);
//         }
//     }
// }

// /**
//  * @brief Obsługuje przekierowanie wejścia (`<`).
//  *
//  * @param minishell Struktura minishell.
//  * @param index Wskaźnik na bieżącą pozycję w linii poleceń.
//  */
// void handle_input_redirection(t_minishell *minishell, int *index)
// {
//     // Przykład: < input.txt
//     skip_whitespace(minishell->line, index);
//     char *filename = ft_lexter_next_token(&minishell->line[*index],
// minishell, &(minishell->cmd_list->infile));
//     if (filename == NULL)
//     {
//         ft_panic("Syntax error: expected filename after '<'", 1);
//     }
//     *index += ft_strlen(filename); // Zakładamy,
// że funkcja zwraca długość przetworzonego tokena
// }

// /**
//  * @brief Obsługuje przekierowanie wyjścia (`>`).
//  *
//  * @param minishell Struktura minishell.
//  * @param index Wskaźnik na bieżącą pozycję w linii poleceń.
//  */
// void handle_output_redirection(t_minishell *minishell, int *index)
// {
//     // Przykład: > output.txt
//     skip_whitespace(minishell->line, index);
//     char *filename = ft_lexter_next_token(&minishell->line[*index],
// minishell, &(minishell->cmd_list->outfile));
//     if (filename == NULL)
//     {
//         ft_panic("Syntax error: expected filename after '>'", 1);
//     }
//     *index += ft_strlen(filename);
// }

// /**
//  * @brief Obsługuje przekierowanie append (`>>`).
//  *
//  * @param minishell Struktura minishell.
//  * @param index Wskaźnik na bieżącą pozycję w linii poleceń.
//  */
// void handle_append_redirection(t_minishell *minishell, int *index)
// {
//     // Przykład: >> output.txt
//     skip_whitespace(minishell->line, index);
//     char *filename = ft_lexter_next_token(&minishell->line[*index],
// minishell, &(minishell->cmd_list->append));
//     if (filename == NULL)
//     {
//         ft_panic("Syntax error: expected filename after '>>'", 1);
//     }
//     *index += ft_strlen(filename);
// }

// /**
//  * @brief Obsługuje heredoc (`<<`).
//  *
//  * @param minishell Struktura minishell.
//  * @param index Wskaźnik na bieżącą pozycję w linii poleceń.
//  */
// void handle_heredoc_token(t_minishell *minishell, int *index)
// {
//     // Przykład: << EOF
//     skip_whitespace(minishell->line, index);
//     char *limiter = ft_lexter_next_token(&minishell->line[*index],
// minishell,
// &(minishell->cmd_list->heredoc_limiter));
//     if (limiter == NULL)
//     {
//         ft_panic("Syntax error: expected limiter after '<<'", 1);
//     }
//     *index += ft_strlen(limiter);
// }

// /**
//  * @brief Pomija białe znaki w linii poleceń.
//  *
//  * @param line Linia poleceń.
//  * @param index Wskaźnik na bieżącą pozycję.
//  */
// void skip_whitespace(char *line, int *index)
// {
//     while (line[*index] && ft_strchr(" \t", line[*index]))
//         (*index)++;
// }
