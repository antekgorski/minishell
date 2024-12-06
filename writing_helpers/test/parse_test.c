#include "../headers/minishell.h"

//cc parse_test.c ../c_files/parser.c -L ../libft -lft

//gcc main.c -L minilibx-linux -lmlx -lX11 -lXext
//gcc main.c -L minilibx-linux -lmlx -lX11 -lXext -g -L libft++ -lft++ -lm

///a.out | cat -e

int main(int argc, char **argv)
{
    char	*line;
    char    **tab_pipe;
    line = "ls -l | wc -l|";
    tab_pipe = parse(line);
    while (*tab_pipe)
    {
        printf("%s\n", *tab_pipe);
        tab_pipe++;
    }
    return (0);
}  