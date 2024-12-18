#include "minishell.h"

//cc env_list_test.c ../source/env.c -I../headers -L ../libft -lft -g

int	main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    t_minishell minishell;
    envinit(&minishell, envp);
    minishell.lexter_tab = NULL;
    while(minishell.m_env)
    {
        printf("%s\n", (char *)minishell.m_env->content);
        minishell.m_env = minishell.m_env->next;
    }
    
    return 0;
}