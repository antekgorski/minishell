/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <dmoroz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:28:38 by sehosaf           #+#    #+#             */
/*   Updated: 2024/07/27 13:29:39 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	set_redir(t_pipeline *nd, int i, char **s_field, int ck_char);

/*
	Finds tokens which define redirection, set respective t_command values
	and drop such tokens. Designed to work with cases where there is only
	one type of in and out redirections.
*/
int	set_redirections(t_pipeline *node)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (node->cmd.args[i])
	{
		if (node->cmd.args[i][0] == '<')
		{
			if (node->cmd.args[i][1] == '<')
				res = set_redir(node, i, &node->cmd.limiter, 2);
			else
				res = set_redir(node, i, &node->cmd.infile, 1);
		}
		else if (node->cmd.args[i][0] == '>')
			res = set_redir(node, i, &node->cmd.outfile, 1);
		else
			i++;
		if (res)
			return (res);
	}
	return (res);
}

static int	set_redir(t_pipeline *nd, int i, char **s_field, int ck_char)
{
	char	*arg;

	if (nd->cmd.args[i][1] == '<')
		nd->cmd.is_heredoc = 1;
	if (nd->cmd.args[i][1] == '>')
		nd->cmd.ap_mode = ck_char++;
	if (!nd->cmd.args[i + 1] && !nd->cmd.args[i][ck_char])
	{
		ft_putstr_fd(ERR_SNX_TOKEN, STDERR_FILENO);
		ft_putstr_fd(nd->cmd.args[i], STDERR_FILENO);
		ft_putendl_fd("`", STDERR_FILENO);
		return (1);
	}
	arg = nd->cmd.args[i];
	if (arg[ck_char] == 0)
	{
		*s_field = ft_strdup(nd->cmd.args[i + 1]);
		remove_cmd_arg(nd, i + 1);
	}
	else
		*s_field = ft_substr(arg, ck_char, ft_strlen(arg));
	remove_cmd_arg(nd, i);
	return (0);
}
