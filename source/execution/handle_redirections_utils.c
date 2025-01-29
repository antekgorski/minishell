/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/29 15:23:00 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	has_input_redirection(t_redir *redirs)
{
	t_redir	*temp;

	temp = redirs;
	while (temp)
	{
		if (temp->type == IREDIR || temp->type == HERDOC)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	has_output_redirection(t_redir *redirs)
{
	t_redir	*temp;

	temp = redirs;
	while (temp)
	{
		if (temp->type == OREDIR || temp->type == APPEND)
			return (1);
		temp = temp->next;
	}
	return (0);
}
