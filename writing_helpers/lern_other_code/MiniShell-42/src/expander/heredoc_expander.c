/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expander.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:22:31 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/02 10:34:03 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_heredoc_expand_writer(char *str, int i, int fd,
		t_content *minishell)
{
	int		start;
	char	*tmp;

	start = ++i;
	if (str[i] == '?')
		return (ft_putnbr_fd(minishell->exit_state, fd), 2);
	while (str[i] && str[i] != '$' && str[i] != ' ')
		i++;
	if (i != start)
	{
		tmp = ft_substr(str, start, i);
		tmp = ft_get_envlst_val(tmp, minishell);
		if (tmp)
			ft_putstr_fd(tmp, fd);
	}
	return (i);
}

void	ft_heredoc_expander(char *str, int fd, t_content *minishell)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			i += ft_heredoc_expand_writer(str, i, fd, minishell);
		else
			i += (ft_putchar_fd(str[i], fd), 1);
	}
	ft_putchar_fd('\n', fd);
}
