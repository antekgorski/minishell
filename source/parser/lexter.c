/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:30:40 by agorski           #+#    #+#             */
/*   Updated: 2025/01/17 14:07:07 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// to też dodałem
t_cmd	*ft_lstnew_cmd(void)
{
	t_cmd	*new_cmd;

	new_cmd = malloc(sizeof(t_cmd));
	if (!new_cmd)
		return (NULL);
	new_cmd->cmd = NULL;
	new_cmd->infile = NULL;
	new_cmd->outfile = NULL;
	new_cmd->infile_fd = -1;
	new_cmd->outfile_fd = -1;
	new_cmd->append = NULL;
	new_cmd->heredoc_limiter = NULL;
	new_cmd->is_builtin = 0;
	new_cmd->next = NULL;
	return (new_cmd);
}
// dodałem ja
void	ft_lstadd_back_cmd(t_cmd **cmd_list, t_cmd *new_cmd)
{
	t_cmd	*current;

	if (!cmd_list || !new_cmd)
		return;
	if (*cmd_list == NULL)
	{
		*cmd_list = new_cmd;
		return;
	}
	current = *cmd_list;
	while (current->next)
		current = current->next;
	current->next = new_cmd;
}

// my version
char	**ft_addline(t_minishell *minishell, char *line, t_token token)
{
	char	**new_argv;
	int		i;
	t_cmd	*new_cmd;

	i = 0;
	while (minishell->lexter_tab && minishell->lexter_tab[i])
		i++;
	new_argv = ft_calloc(sizeof(char *) * (i + 2), 1);
	if (new_argv == NULL)
		ft_panic("malloc", 1);
	i = 0;
	while (minishell->lexter_tab && minishell->lexter_tab[i])
	{
		new_argv[i] = minishell->lexter_tab[i];
		i++;
	}
	new_argv[i] = line;
	ft_get_token(token, minishell);
	new_argv[i + 1] = NULL;
	if (token == PIPE)
	{
		new_cmd = ft_lstnew_cmd();
		if (!new_cmd)
			ft_panic("malloc failed", 1);
		ft_lstadd_back_cmd(&minishell->cmd_list, new_cmd);
	}
	if (minishell->lexter_tab)
	{
		free(minishell->lexter_tab);
		minishell->lexter_tab = NULL;
	}
	return (new_argv);
}
/** antek's version
 * @attention MALOC
 * @brief line to the lexter_tab
 * if the lexter_tab is NULL it will create a new one
 * if the lexter_tab is not NULL it will add a new line to it
 * and then it will free the old one
 * and return the new one
 * they also get the token from the lexter and add it to the token_list
 * @return ** to new tab
 */
// char	**ft_addline(t_minishell *minishell, char *line, t_token token)
// {
// 	char	**new_argv;
// 	int		i;

// 	i = 0;
// 	while (minishell->lexter_tab && minishell->lexter_tab[i])
// 		i++;
// 	new_argv = ft_calloc(sizeof(char *) * (i + 2), 1);
// 	if (new_argv == NULL)
// 		ft_panic("malloc", 1);
// 	i = 0;
// 	while (minishell->lexter_tab && minishell->lexter_tab[i])
// 	{
// 		new_argv[i] = minishell->lexter_tab[i];
// 		i++;
// 	}
// 	new_argv[i] = line;
// 	ft_get_token(token, minishell);
// 	new_argv[i + 1] = NULL;
// 	if (minishell->lexter_tab)
// 	{
// 		free(minishell->lexter_tab);
// 		minishell->lexter_tab = NULL;
// 	}
// 	return (new_argv);
// }

void	ft_lexter(t_minishell *minishell)
{
	char	*temp_line;

	temp_line = minishell->line;
	while (*temp_line)
	{
		if (ft_strchr(SYMBOLS_D, *temp_line))
		{
			if (*temp_line == ' ' || *temp_line == '\t')
				temp_line++;
			if (*temp_line == '\'')
				temp_line += ft_squote(temp_line, minishell);
			if (*temp_line == '\"')
				temp_line += ft_dquote(temp_line, minishell);
			if (*temp_line == '|')
				temp_line += ft_pipe(minishell);
			if (*temp_line == '<')
				temp_line += ft_iredir(temp_line, minishell);
			if (*temp_line == '>')
				temp_line += ft_oredir(temp_line, minishell);
		}
		else
			temp_line += ft_comend(temp_line, minishell);
	}
}
