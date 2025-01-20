/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:23:41 by agorski           #+#    #+#             */
/*   Updated: 2025/01/20 10:00:46 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

// void	ft_parser_test(t_minishell *minishell)
// {
// 	int		i;
// 	t_list	*temp;

// 	temp = minishell->token_list;
// 	i = 0;
// 	while (minishell->lexter_tab[i])
// 	{
// 		printf("%s\t%i\n", minishell->lexter_tab[i], *(int *)temp->content);
// 		i++;
// 		temp = temp->next;
// 	}
// }
// void	ft_parser_test(t_minishell *minishell)
// {
// 	t_cmd	*current_cmd;
// 	int		i;

// 	current_cmd = minishell->cmd_list;
// 	int cmd_num = 1;
// 	while (current_cmd)
// 	{
// 		printf("Command %d:\n", cmd_num);
// 		if (current_cmd->cmd)
// 		{
// 			printf("  Command: ");
// 			i = 0;
// 			while (current_cmd->cmd[i])
// 			{
// 				printf("%s ", current_cmd->cmd[i]);
// 				i++;
// 			}
// 			printf("\n");
// 		}
// 		else
// 		{
// 			printf("  Command: (null)\n");
// 		}
// 		if (current_cmd->infile)
// 			printf("  Infile: %s\n", current_cmd->infile);
// 		if (current_cmd->outfile)
// 			printf("  Outfile: %s\n", current_cmd->outfile);
// 		if (current_cmd->append)
// 			printf("  Append: %s\n", current_cmd->append);
// 		if (current_cmd->heredoc_limiter)
// 			printf("  Heredoc Limiter: %s\n", current_cmd->heredoc_limiter);
// 		current_cmd = current_cmd->next;
// 		cmd_num++;
// 	}
// }

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
		minishell->f_signal = e_bild(minishell->lexter_tab, minishell);
		// ft_parser_test(minishell);
		printf("Contents of lexter_tab:\n");
		for (int i = 0; minishell->lexter_tab[i] != NULL; i++)
		{
			printf("[%d]: %s\n", i, minishell->lexter_tab[i]);
		}
	}
	if (minishell->lexter_tab != NULL)
		tab_free(&minishell->lexter_tab);
	if (minishell->token_list != NULL)
		ft_token_free(&minishell->token_list);
	free(minishell->l_hdr);
}
