/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bilder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:39:36 by agorski           #+#    #+#             */
/*   Updated: 2025/01/23 14:24:30 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"/*./headers/*/

t_cmd	*ft_new_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		ft_panic("malloc", 1);
	cmd->argv = NULL;
	cmd->redirs = NULL;
	cmd->next = NULL;
	return (cmd);
}

void	ft_add_redir(t_redir **redirs, t_token type, char *filename)
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
char	**ft_add_cmd(char **argv, char *line)
{
	char	**new_argv;
	int		i;

	i = 0;
	while (argv && argv[i])
	while (argv && argv[i])
		i++;
	new_argv = ft_calloc(sizeof(char *) * (i + 2), 1);
	if (new_argv == NULL)
		ft_panic("malloc", 1);
	i = 0;
	while (argv && argv[i])
	while (argv && argv[i])
	{
		new_argv[i] = argv[i];
		new_argv[i] = argv[i];
		i++;
	}
	new_argv[i] = ft_strdup(line);
	new_argv[i + 1] = NULL;
	if (argv)
		free(argv);
	argv = NULL;
	return (new_argv);
}

bool	ft_cmd_redir(t_minishell *minishell, t_cb *cb, t_token *redir_type)
{
	*redir_type = *(t_token *)cb->token->content;
	cb->token = cb->token->next;
	cb->i++;
	if (minishell->lexter_tab[cb->i] && *(t_token *)cb->token->content == CMD)
		ft_add_redir(&cb->c_cmd->redirs, *redir_type,
			minishell->lexter_tab[cb->i]);
	else
	{
		printf("syntax error near unexpected token\n");
		return (false);
	}
	return (true);
}

void	ft_cmd_bilder(t_minishell *minishell)
{
	t_cb	cb;
	t_token	redir_type;

	ft_cb_init(&cb, minishell);
	while (cb.token)
	{
		if (*(t_token *)cb.token->content == PIPE)
		{
			cb.c_cmd->next = ft_new_cmd();
			cb.c_cmd = cb.c_cmd->next;
		}
		else if (ft_check_redir(cb.token))
		{
			if (!ft_cmd_redir(minishell, &cb, &redir_type))
				return ;
		}
		else if (*(t_token *)cb.token->content == CMD)
			cb.c_cmd->argv = ft_add_cmd(cb.c_cmd->argv,
					minishell->lexter_tab[cb.i]);
		cb.token = cb.token->next;
		cb.i++;
	}
	minishell->cmd_list = cb.cmds;
}
