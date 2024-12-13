#include <stdio.h>

void main(int argc, char*argv[], char **env)
{
    // Przykład przetwarzania zmiennych środowiskowych
    for (char **envp = env; *envp != 0; envp++) {
        char *thisEnv = *envp;
        printf("%s\n", thisEnv); // Wypisanie zmiennej środowiskowej
    }
}