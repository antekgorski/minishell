/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexter_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:59:04 by agorski           #+#    #+#             */
/*   Updated: 2025/01/19 15:19:05 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pipe(t_minishell *minishell)
{
	char	*temp_arg;

	temp_arg = ft_strdup("|");
	minishell->lexter_tab = ft_addline(minishell, temp_arg, PIPE);
	temp_arg = NULL;
	return (1);
}
// static int	ft_lexter_next_token(char *line,char **dest)
// {
// 	char	*token;
// 	int		i;

// 	i = 0;
// 	while (line[i] && ft_strchr(" \t", line[i]))
// 		i++;
// 	int start = i;
// 	while (line[i] && !ft_strchr(" \t|<>", line[i]))
//         i++;
// 	token = ft_substr(line, start, i - start);
// 	*dest = token;
// 	return (i);
// }
// int	ft_oredir(char *temp_line, t_minishell *minishell)
// {
// 	char	*temp_arg;
// 	int	consumed = 0;

// 	if (*(temp_line + 1) == '>')
// 	{
// 		temp_arg = ft_strdup(">>");
// 		minishell->lexter_tab = ft_addline(minishell, temp_arg, APPEND);
// 		// temp_arg = NULL;
// 		free(temp_arg);
// 		consumed = ft_lexter_next_token(temp_line + 2, &(minishell->cmd_list->append));
// 		return (2 + consumed);
// 	}
// 	else
// 	{
// 		temp_arg = ft_strdup(">");
// 		minishell->lexter_tab = ft_addline(minishell, temp_arg, OREDIR);
// 		// temp_arg = NULL;
// 		free(temp_arg);
// 		ft_lexter_next_token(temp_line + 1, &(minishell->cmd_list->outfile));
// 		return (1 + consumed);
// 	}
// }

// Antek's version
int	ft_oredir(char *temp_line, t_minishell *minishell)
{
	char	*temp_arg;

	if (*(temp_line + 1) == '>')
	{
		temp_arg = ft_strdup(">>");
		minishell->lexter_tab = ft_addline(minishell, temp_arg, APPEND);
		temp_arg = NULL;
		return (2);
	}
	else
		temp_arg = ft_strdup(">");
	minishell->lexter_tab = ft_addline(minishell, temp_arg, OREDIR);
	temp_arg = NULL;
	return (1);
}

// int	ft_iredir(char *temp_line, t_minishell *minishell)
// {
// 	char	*temp_arg;
// 	int	consumed = 0;
// 	if (*(temp_line + 1) == '<')
// 	{
// 		temp_arg = ft_strdup("<<");
// 		minishell->lexter_tab = ft_addline(minishell, temp_arg, HERDOC);
// 		// temp_arg = NULL;
// 		free(temp_arg);
// 		consumed = ft_lexter_next_token(temp_line + 2, &(minishell->cmd_list->heredoc_limiter));
// 		return (2 + consumed);
// 	}
// 	else
// 	{
// 		temp_arg = ft_strdup("<");
// 		minishell->lexter_tab = ft_addline(minishell, temp_arg, IREDIR);
// 		// temp_arg = NULL;
// 		free(temp_arg);
// 		consumed = ft_lexter_next_token(temp_line + 1, &(minishell->cmd_list->infile));
// 		return (1 + consumed);
// 	}
// }

// Antek's version
int	ft_iredir(char *temp_line, t_minishell *minishell)
{
	char	*temp_arg;

	if (*(temp_line + 1) == '<')
	{
		temp_arg = ft_strdup("<<");
		minishell->lexter_tab = ft_addline(minishell, temp_arg, HERDOC);
		temp_arg = NULL;
		return (2);
	}
	else
		temp_arg = ft_strdup("<");
	minishell->lexter_tab = ft_addline(minishell, temp_arg, IREDIR);
	temp_arg = NULL;
	return (1);
}
