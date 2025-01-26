/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexter_parser_tester.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:06:12 by agorski           #+#    #+#             */
/*   Updated: 2025/01/26 21:10:41 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/**
 * @brief Function to handle the input from the user
 */
static char	*s_input(char *line)
{
	char	*temp;
	int		i;

	i = 0;
	temp = line;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			temp[i] = '\0';
			break ;
		}
		i++;
	}
	return (temp);
}

# include "minishell.h"


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
