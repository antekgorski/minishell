#include "../../headers/minishell.h"

//cc parse_quote_test.c ../../source/parse_quote.c -L ../../libft -lft

int main()
{
    int i;
    i = 0;
    char *line = "111111 12222 222  333'33'33 444444 5555555 \"6666666";
    i = check_quote(line);
    if (i == 1)
        exit(1);
    printf("quote_check return is:%d\n", i);
    printf("%s\n", line);
}