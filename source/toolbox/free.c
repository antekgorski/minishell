/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:23:49 by agorski           #+#    #+#             */
/*   Updated: 2025/01/23 14:13:45 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//dodałem
// static void free_cmd_list(t_cmd *cmd_list)
// {
// 	t_cmd	*current;
// 	t_cmd	*next;

// 	current = cmd_list;
// 	while (current)
// 	{
// 		next = current->next;
// 		if (current->cmd)
// 			ft_free_split(current->cmd);
// 		if (current->infile)
// 			free(current->infile);
// 		if (current->outfile)
// 			free(current->outfile);
// 		if (current->append)
// 			free(current->append);
// 		if (current->heredoc_limiter)
// 			free(current->heredoc_limiter);
// 		free(current);
// 		current = next;
// 	}
// }
void	ft_shell_free(t_minishell *minishell)
{
	tab_free(&minishell->lexter_tab);
	free(minishell->line);
	env_free(minishell->m_env);
	ft_token_free(&minishell->token_list);
	ft_free_cmd_list(minishell->cmd_list);
	free(minishell->l_hdr);
	// free_cmd_list(minishell->cmd_list);
}

/**
 * @brief 	Frees a two-dimensional array of strings.
 * 			Each string in the array is freed, then the array itself is freed.
 * @param lextab The array of strings to be freed.
 * @note	The array itself is also freed,
 *			so the pointer to it will be set to NULL.
 */
void	tab_free(char ***lexter_tab)
{
	int	i;

	if (*lexter_tab == NULL)
		return ;
	i = 0;
	while ((*lexter_tab)[i] && (*lexter_tab)[i] != NULL)
	{
		free((*lexter_tab)[i]);
		(*lexter_tab)[i] = NULL;
		i++;
	}
	free(*lexter_tab);
	*lexter_tab = NULL;
}

void	env_free(t_list *env)
{
	t_list	*tmp;
	char	**env_vars;

	if (env == NULL)
		return ;
	while (env)
	{
		tmp = env;
		env_vars = (char **)env->content;
		if (env_vars != NULL)
		{
			free(env_vars[0]);
			env_vars[0] = NULL;
			free(env_vars[1]);
			env_vars[1] = NULL;
			free(env_vars);
			env_vars = NULL;
		}
		env = env->next;
		free(tmp);
		tmp = NULL;
	}
	env = NULL;
}

void	ft_token_free(t_list **token_list)
{
	t_list	*tmp;
	t_token	*token;

	if (*token_list == NULL)
		return ;
	while (*token_list)
	{
		tmp = *token_list;
		token = (t_token *)(*token_list)->content;
		if (token != NULL)
		{
			free(token);
			token = NULL;
		}
		*token_list = (*token_list)->next;
		if (tmp != NULL)
		{
			free(tmp);
			tmp = NULL;
		}
	}
	*token_list = NULL;
}

/**
 * @brief 	Frees a linked list of commands.
 * 			Each command in the list is freed, then the list itself is freed.
 * @param cmd The linked list of commands to be freed.
 * @note	The list itself is also freed,
 * 			so the pointer to it will be set to NULL.
 */
void	ft_free_cmd_list(t_cmd *cmd)
{
	t_cmd	*temp;
	t_redir	*temp_redir;

	while (cmd)
	{
		temp = cmd;
		cmd = cmd->next;
		if (temp->argv)
			tab_free(&temp->argv);
		while (temp->redirs)
		{
			temp_redir = temp->redirs;
			temp->redirs = temp->redirs->next;
			free(temp_redir->filename);
			temp_redir->filename = NULL;
			free(temp_redir);
			temp_redir = NULL;
		}
		free(temp);
		temp = NULL;
	}
}
