/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:32:25 by sehosaf           #+#    #+#             */
/*   Updated: 2024/07/18 13:56:59 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_pipeline(t_pipeline *p)
{
	t_pipeline	*tmp;

	while (p != NULL)
	{
		tmp = p;
		p = p->next;
		free_split(tmp->cmd.args);
		free(tmp->cmd.limiter);
		free(tmp->cmd.outfile);
		free(tmp->cmd.infile);
		if (tmp->fd_in > 2)
			close(tmp->fd_in);
		if (tmp->fd_out > 2)
			close(tmp->fd_out);
		free(tmp);
	}
}
