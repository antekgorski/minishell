/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_pipeline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:35:43 by sehosaf           #+#    #+#             */
/*   Updated: 2024/07/17 11:22:33 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_con_type(t_connection c);

int	validate_pipeline(t_pipeline *p)
{
	t_pipeline	*current;
	t_command	*cmd;

	current = p;
	while (current)
	{
		cmd = &current->cmd;
		if (!cmd->args || !cmd->args[0])
		{
			if (current->next)
			{
				ft_putendl_fd(ERR_SNX_TOKEN, STDERR_FILENO);
				ft_putendl_fd(
					get_con_type(current->next->cmd.conn_type), STDERR_FILENO);
				ft_putendl_fd("'", STDERR_FILENO);
			}
			else
				ft_putendl_fd(ERR_SNX_EOF, STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		current = current->next;
	}
	return (EXIT_SUCCESS);
}

char	*get_con_type(t_connection c)
{
	if (c == CON_PIPE)
		return ("|");
	if (c == CON_OR)
		return ("||");
	if (c == CON_AND)
		return ("&&");
	return ("NONE");
}
