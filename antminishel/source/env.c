#include "minishell.h"

void	envinit(t_minishell *minishell, char **envp)
{
	char	**tmp_env;

	tmp_env = envp;
	while (*tmp_env)
	{
		if (minishell->m_env == NULL)
		{
			minishell->m_env = ft_lstnew(ft_strdup(*tmp_env));
		}
		else
		{
			ft_lstadd_back(&minishell->m_env, ft_lstnew(ft_strdup(*tmp_env)));
		}
		tmp_env++;
	}
}
