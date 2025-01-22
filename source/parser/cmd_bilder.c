/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bilder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:39:36 by agorski           #+#    #+#             */
/*   Updated: 2025/01/22 17:33:04 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*ft_new_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->argv = NULL;
	cmd->redirs = NULL;
	cmd->next = NULL;
	return (cmd);
}

static void	ft_add_redir(t_redir **redirs, t_token type, char *filename)
{
	t_redir	*new;
	t_redir	*temp;

	new = malloc(sizeof(t_redir));
	if (!new)
		return ;
	new->type = type;
	new->filename = ft_strdup(filename);
	new->next = NULL;
	if (!*redirs)
		*redirs = new;
	else
	{
		temp = *redirs;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

static char	**ft_add_cmd(char **argv, char *line)
{
	char	**new_argv;
	int		i;

	i = 0;
	while (argv && argv[i])
		i++;
	new_argv = ft_calloc(sizeof(char *) * (i + 2), 1);
	if (new_argv == NULL)
		ft_panic("malloc", 1);
	i = 0;
	while (argv && argv[i])
	{
		new_argv[i] = argv[i];
		i++;
	}
	new_argv[i] = line;
	new_argv[i + 1] = NULL;
	if (argv)
		free(argv);
	return (new_argv);
}

void	ft_cmd_bilder(t_minishell *minishell)
{
	t_cmd	*cmds;
	t_cmd	*current_cmd;
	int		i;
	t_list	*token;

	token = minishell->token_list;
	cmds = ft_new_cmd();
	if (!cmds)
		ft_panic("malloc", 1);
	current_cmd = cmds;
	i = 0;
	while (token)
	{
		if (*(t_token *)token->content == PIPE)
		{
			current_cmd->next = ft_new_cmd();
			if (!current_cmd->next)
				ft_panic("malloc", 1);
			current_cmd = current_cmd->next;
		}
		else if (*(t_token *)token->content == IREDIR
			|| *(t_token *)token->content == OREDIR
			|| *(t_token *)token->content == APPEND
			|| *(t_token *)token->content == HERDOC)
		{
			t_token temp = *(t_token *)token->content;
			token = token->next;
			i++;
			if (minishell->lexter_tab[i] && *(t_token *)token->content == CMD)
				ft_add_redir(&current_cmd->redirs, temp,
					minishell->lexter_tab[i]);
			else
			{
				printf("syntax error near unexpected token\n");
				return ;
			}
		}
		else if (*(t_token *)token->content == CMD)
			current_cmd->argv = ft_add_cmd(current_cmd->argv,
					minishell->lexter_tab[i]);

		token = token->next;
		i++;
	}
	minishell->cmd_list = cmds;
}

// void	ft_cmd_bilder(t_minishell *minishell)
// {
// 	t_cmd	*cmds;
// 	t_cmd	*current_cmd;
// 	int		i;
// 	t_list	*token;

// 	token = minishell->token_list;
// 	cmds = ft_new_cmd();
// 	if (!cmds)
// 		ft_panic("malloc", 1);
// 	current_cmd = cmds;
// 	i = 0;
// 	while (minishell->lexter_tab[i])
// 	{
// 		if ((t_token)token->content == PIPE)
// 		{
// 			current_cmd->next = ft_new_cmd();
// 			if (!current_cmd->next)
// 				ft_panic("malloc", 1);
// 			current_cmd = current_cmd->next;
// 		}
// 		else if (*(int *)token->content == IREDIR
// 			|| *(int *)token->content == OREDIR
// 			|| *(int *)token->content == APPEND
// 			|| *(int *)token->content == HERDOC)
// 		{
// 			token = token->next;
// 			i++;
// 			if (minishell->lexter_tab[i] && *(int *)token->content == CMD)
// 				ft_add_redir(&current_cmd->redirs, (t_token)token->content,
// 					minishell->lexter_tab[i]);
// 			else
// 			{
// 				printf("syntax error near unexpected token\n");
// 				return ;
// 			}
// 		}
// 		else if (*(int *)token->content == CMD)
// 			current_cmd->argv = ft_add_cmd(current_cmd->argv,
// 					minishell->lexter_tab[i]);
// 		token = token->next;
// 		i++;
// 	}
// 	minishell->cmd_list = cmds;
// }
