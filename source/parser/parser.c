/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:23:41 by agorski           #+#    #+#             */
/*   Updated: 2025/01/27 14:04:26 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parser_test(t_minishell *minishell)
{
	int		i;
	t_list	*temp;
	temp = minishell->token_list;
	i = 0;
	while (minishell->lexter_tab[i])
	{
		printf("%s\t%i\n", minishell->lexter_tab[i], *(int *)temp->content);
		i++;
		temp = temp->next;
	}
}
void	print_cmds(t_cmd *cmds)
{
	t_redir	*redirs;
	int		i;
	while (cmds)
	{
		printf("Command:\n");
		if (cmds->argv)
		{
			i = 0;
			while (cmds->argv[i])
			{
				printf("  argv[%d]: %s\n", i, cmds->argv[i]);
				i++;
			}
		}
		redirs = cmds->redirs;
		while (redirs)
		{
			printf("  Redirection: type = %d, file = %s\n", redirs->type,
				redirs->filename);
			redirs = redirs->next;
		}
		cmds = cmds->next;
	}
}

/**
 *function to get token
 *it will create a new node and add it to the token_list
 *it will create a new token and add it to the node
 *it will take the token prom lexter to the new token
 *and add the new node to the token_list
 */
void	ft_get_token(t_token token, t_minishell *minishell)
{
	t_list	*new_node;
	t_token	*new_token;

	new_token = ft_calloc(1, sizeof(t_token));
	if (!new_token)
		ft_panic("Malloc failed", 1);
	*new_token = token;
	new_node = ft_lstnew(new_token);
	if (!new_node)
		ft_panic("Malloc failed", 1);
	ft_lstadd_back(&minishell->token_list, new_node);
}

// check if the quote is closed
// if not it will print the error message
// run lexical analysis
void	parse(t_minishell *minishell)
{
	if (check_quote(minishell->line) == 1)
		return ;
	minishell->lexter_tab = NULL;
	ft_lexter(minishell);
	if (minishell->lexter_tab)
	{
		ft_cmd_bilder(minishell);
		// ft_parser_test(minishell);
		// print_cmds(minishell->cmd_list);
		execute(minishell->cmd_list, minishell);
	}
	if (minishell->lexter_tab != NULL)
		tab_free(&minishell->lexter_tab);
	if (minishell->token_list != NULL)
		ft_token_free(&minishell->token_list);
	if (minishell->cmd_list != NULL)
		ft_free_cmd_list(&minishell->cmd_list);
	free(minishell->l_hdr);
}
