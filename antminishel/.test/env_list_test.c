#include "minishell.h"

//cc env_list_test.c ../source/env.c -I../headers -L ../libft -lft -g

void	minishell_init(t_minishell *minishell, char **envp)
{
	minishell->line = NULL;
	minishell->lexter_tab = NULL;
	minishell->m_env = NULL;
	env_start(minishell, envp);
}

int	main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    t_minishell minishell;
    minishell_init(&minishell, envp);
    while(minishell.m_env)
    {
        printf("%s\n", (char *)minishell.m_env->content);
        minishell.m_env = minishell.m_env->next;
    }
    
    return 0;
}