#include "minishell.h"

void	env_start(t_minishell *minishell, char **envp)
{
	char	**tmp_env;

	tmp_env = envp;
	while (*tmp_env)
	{
		ft_lstadd_back(&minishell->m_env, ft_lstnew(ft_strdup(*tmp_env)));
		tmp_env++;
	}
}
