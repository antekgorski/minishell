#include "../headers/minishell.h"

//cc lexter_test.c ../source/lexter.c -L ../libft -lft

int main()
{
    t_minishell minishell;
    minishell.line = "<  lsls.e<xrt\t|\t$dksj\"nbgf<>$bnjkt\"\t<< < $$$11 22\t 33' 4||4 <5>>,,.5 $66 77 88 '9>>9 <<$ 0<0|";
    minishell.lexter_tab = NULL;
    ft_lexter(&minishell);
    while(*minishell.lexter_tab)
    {
        printf("%s\n", *minishell.lexter_tab);
        minishell.lexter_tab++;
    }
    
}