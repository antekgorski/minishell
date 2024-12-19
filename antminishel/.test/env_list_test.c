#include "minishell.h"

//cc env_list_test.c ../source/env.c ../source/free.c -I../headers -L ../libft -lft -g

void	minishell_init(t_minishell *minishell, char **envp)
{
	minishell->line = NULL;
	minishell->lexter_tab = NULL;
	minishell->m_env = NULL;
	env_start(minishell, envp);
}

// print env list
void	print_env(t_minishell *minishell)
{
    //ptint one env variable

    printf("%s\n%s\n", ((char **)minishell->m_env->content)[0], ((char **)minishell->m_env->content)[1]);
    
    //print all env variables

    // t_list	*current;
	// char	**env_vars;

	// current = minishell->m_env;


	// while (current != NULL)
	// {
	// 	env_vars = (char **)current->content;
	// 	if (env_vars != NULL)
	// 	{
	// 		for (int i = 0; env_vars[i] != NULL; i++)
	// 		{
	// 			printf("env_vars[%d]: %s\n", i, env_vars[i]);
	// 		}
	// 	}
	// 	current = current->next;
	// }

    ft_shell_free(minishell);
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_minishell minishell;
	minishell_init(&minishell, envp);
	print_env(&minishell);
	return (0);
}