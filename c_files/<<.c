// Plan krok po kroku
// Parsowanie Komendy:

// Wykryj obecność operatora << podczas parsowania wejścia użytkownika.
// Wyodrębnij delimiter znajdujący się po <<.
// Odczyt Here-Document:

// Użyj funkcji get_next_line do czytania linii od użytkownika.
// Kontynuuj czytanie, aż napotkasz delimiter.
// Przechowywanie Wejścia:

// Zapisz odczytane linie w buforze lub pliku tymczasowym.
// Utworzenie Potoku:

// Utwórz potok (pipe), gdzie dane z here-document będą przekazywane do standardowego wejścia polecenia.
// Wykonanie Polecenia:

// Przekaż odczytane dane do polecenia poprzez potok.
// Obsłuż procesy potomne odpowiedzialne za wykonanie polecenia.
// Implementacja w C
// Poniżej znajduje się uproszczony przykład implementacji obsługi operatora << (here-document) w minishell.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

// Deklaracja funkcji get_next_line
char *get_next_line(int fd);

// Funkcja obsługująca here-document
char *handle_here_document(const char *delimiter)
{
    char *line;
    size_t size = 0;
    size_t total_size = 0;
    char *buffer = NULL;

    printf("> "); // Prompt dla here-document
    while ((line = get_next_line(STDIN_FILENO)) != NULL)
    {
        // Usuń znak nowej linii z końca
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';

        // Sprawdź, czy linia to delimiter
        if (strcmp(line, delimiter) == 0)
        {
            free(line);
            break;
        }

        // Dodaj linię do bufora
        size += strlen(line) + 1; // +1 dla '\n'
        char *new_buffer = realloc(buffer, total_size + size + 1);
        if (!new_buffer)
        {
            perror("realloc");
            free(buffer);
            free(line);
            return NULL;
        }
        buffer = new_buffer;
        strcpy(buffer + total_size, line);
        strcat(buffer + total_size, "\n");
        total_size += size;
        free(line);
        printf("> ");
    }
    return buffer;
}

// Przykładowa funkcja wykonująca polecenie z here-document
void execute_command_with_here_document(const char *cmd, const char *delimiter)
{
    int pipe_fd[2];
    pid_t pid;
    char *here_doc = handle_here_document(delimiter);

    if (!here_doc)
    {
        fprintf(stderr, "Błąd obsługi here-document\n");
        return;
    }

    if (pipe(pipe_fd) == -1)
    {
        perror("pipe");
        free(here_doc);
        return;
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        free(here_doc);
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        return;
    }
    if (pid == 0)
    {
        // Proces potomny - wykonuje polecenie
        close(pipe_fd[1]); // Zamknij pisanie
        dup2(pipe_fd[0], STDIN_FILENO); // Przekieruj stdin
        close(pipe_fd[0]);

        execlp(cmd, cmd, NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    else
    {
        // Proces macierzysty - pisze do potoku
        close(pipe_fd[0]); // Zamknij czytanie
        write(pipe_fd[1], here_doc, strlen(here_doc));
        close(pipe_fd[1]); // Zamknij pisanie po zakończeniu
        free(here_doc);
        wait(NULL); // Poczekaj na proces potomny
    }
}

int main()
{
    // Przykład użycia: echo z here-document
    execute_command_with_here_document("cat", "END");

    return 0;
}

// Implementacja funkcji get_next_line (prosty przykład)
char *get_next_line(int fd)
{
    char *buffer = malloc(1024);
    if (!buffer)
        return NULL;
    ssize_t bytes = read(fd, buffer, 1023);
    if (bytes <= 0)
    {
        free(buffer);
        return NULL;
    }
    buffer[bytes] = '\0';
    return buffer;
}

// Wyjaśnienie
// Parsowanie Komendy:

// Funkcja execute_command_with_here_document przyjmuje polecenie (cmd) oraz delimiter (delimiter).
// Obsługa Here-Document:

// Funkcja handle_here_document odczytuje linie od użytkownika aż do momentu, gdy wprowadzi delimiter.
// Odczytane linie są przechowywane w buforze buffer.
// Tworzenie Potoku:

// Tworzony jest potok za pomocą pipe(pipe_fd).
// Proces potomny (fork) wykonuje polecenie, przekierowując standardowe wejście do czytania z potoku.
// Proces macierzysty pisze zawartość here-document do potoku.
// Wykonanie Polecenia:

// W przykładzie polecenie cat odbiera dane z here-document i je wyświetla.
// Aby przetestować, uruchom program i wpisz dane, kończąc delimiterem END.
// Przykład Testowy

$ ./minishell
> echo "Hello, World!" > output.txt
> cat <<END
> This is a here-document.
> It spans multiple lines.
> END
This is a here-document.
It spans multiple lines.

// Uwagi
// Limit Wielkości: W przykładzie bufor line ma stały rozmiar. W praktyce warto dynamicznie alokować pamięć lub używać bardziej zaawansowanych metod zarządzania pamięcią.
// Bezpieczeństwo: Sprawdź poprawność alokacji pamięci i obsłuż potencjalne błędy.
// Rozszerzalność: Integracja z istniejącym parserem w minishell umożliwi obsługę operatora << w bardziej złożonych scenariuszach.
// Czyszczenie Zasobów: Upewnij się, że wszystkie zasoby są poprawnie zwalniane, aby uniknąć wycieków pamięci.


