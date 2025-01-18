/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexter_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:05:29 by agorski           #+#    #+#             */
/*   Updated: 2025/01/18 08:52:08 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_comend(char *t_line, t_minishell *minishell)
{
	int	i;
	char	*temp_arg;
	char	**split_cmd;

	i = 0;
	while (t_line[i] && !ft_strchr(SYMBOLS_D, t_line[i]))
		i++;
	temp_arg = ft_substr(t_line, 0, i);
	if (!temp_arg)
		ft_panic("malloc failed", 1);

	split_cmd = ft_split(temp_arg, ' ');
	 // Debugging
    printf("ft_comend: Parsed command: ");
	int j = 0;
    while (split_cmd[j] )
	{
		printf("%s ", split_cmd[j]);
		j++;
	}
	printf("\n");

	if (!split_cmd)
	{
		free(temp_arg);
		ft_panic("malloc failed", 1);
	}
	free(temp_arg);
	minishell->cmd_list->cmd = split_cmd;

	// if (ft_strchr(SYMBOLS_C, t_line[i]))
	// {
	// 	minishell->lexter_tab = ft_addline(minishell, minishell->cmd_list->cmd[0], CMD);
	// 	minishell->cmd_list->cmd = NULL;
	// }
	return(i);
}
// antek's version
// int	ft_comend(char *t_line, t_minishell *minishell)
// {
// 	int		i;
// 	char	*temp_arg;
// 	char	*result;
// 	char	*temp_hdr;

// 	i = 0;
// 	while (t_line[i] && !ft_strchr(SYMBOLS_D, t_line[i]))
// 		i++;
// 	temp_arg = ft_substr(t_line, 0, i);
// 	result = ft_d_roll(temp_arg, minishell);
// 	free(temp_arg);
// 	temp_hdr = ft_strjoin(minishell->l_hdr, result);
// 	free(minishell->l_hdr);
// 	minishell->l_hdr = NULL;
// 	free(result);
// 	result = NULL;
// 	minishell->l_hdr = temp_hdr;
// 	if (ft_strchr(SYMBOLS_C, t_line[i]))
// 	{
// 		minishell->lexter_tab = ft_addline(minishell, minishell->l_hdr, CMD);
// 		minishell->l_hdr = NULL;
// 	}
// 	return (i);
// }
