/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bilder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:39:36 by agorski           #+#    #+#             */
/*   Updated: 2025/01/20 16:12:54 by agorski          ###   ########.fr       */
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
	return (cmd);
}

static void	add_redir(t_redir **redirs, t_token type, char *filename)
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

static char **ft_add_cmd(char **argv, char *arg)
{
    int     i;
    char    **new_argv;
    i = 0;
    while (argv && argv[i])
        i++;
    new_argv = malloc(sizeof(char *) * (i + 2));
    if (!new_argv)
        return (NULL);
    i = 0;
    while (argv && argv[i])
    {
        new_argv[i] = argv[i];
        i++;
    }
    new_argv[i] = ft_strdup(arg);
    new_argv[i + 1] = NULL;
    free(argv);
    return (new_argv);
}

static char	**ft_add_cmd(t_minishell *minishell, char *line, t_token token)
{
	char **new_argv;
	int i;

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
	if (minishell->lexter_tab)
	{
		free(minishell->lexter_tab);
		minishell->lexter_tab = NULL;
	}
	return (new_argv);
}

void	ft_cmd_bilder(t_minishell *minishell)
{
	t_cmd	*cmds;
	t_cmd	*current_cmd;
	t_list	*temp;
	int		i;

	t_list token;
	token = minishell->token_list;
	cmds = ft_new_cmd();
	if (!cmds)
		ft_panic("malloc", 1);
	current_cmd = cmds;
	i = 0;
	while (minishell->token_list)
	{
		if (*(int *)token->content == PIPE)
		{
			current_cmd->next = ft_new_cmd();
			if (!current_cmd->next)
				ft_panic("malloc", 1);
			current_cmd = current_cmd->next;
		}
		else if (*(int *)token->content == IREDIR
			|| *(int *)token->content == OREDIR
			|| *(int *)token->content == APPEND
			|| *(int *)token->content == HERDOC)
		{
			token = *(int *)token->content;
			token = token->next;
			i++;
			if (minishell->lexter_tab[i] && token->content == CMD)
				ft_add_redir(&current_cmd->redirs, token,
					minishell->lexter_tab[i]);
			else
				return (printf("syntax error near unexpected token\n"), 1);
		}
		else if (*(int *)token->content == CMD)
			current_cmd->argv = ft_add_cmd(current_cmd->argv, minishell->lexter_tab[i]) 
		token = token->next;
		i++;
	}
	return (cmds);
}
