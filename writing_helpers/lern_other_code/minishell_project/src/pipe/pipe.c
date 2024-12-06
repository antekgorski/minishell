/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:56:55 by sehosaf           #+#    #+#             */
/*   Updated: 2024/07/17 12:50:07 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

/**
 * @brief Creates and assigns the file descriptors for the redirections
 * @param pipeline The pipeline to create the redirections for
 * @return EXIT_SUCCESS or EXIT_FAILURE
 */
int	create_pipes(t_pipeline *pipeline)
{
	int			pipefd[MAX_CMD][2];
	t_pipeline	*current;
	int			i;

	current = pipeline;
	if (!pipeline)
		return (EXIT_FAILURE);
	i = 0;
	while (current)
	{
		if (current->cmd.conn_type == CON_PIPE)
		{
			if (pipe(pipefd[i]) == -1)
				return (perror(ERR_PIPE), EXIT_FAILURE);
			current->fd_in = pipefd[i][0];
			current->fd_out = pipefd[i][1];
			i++;
		}
		current = current->next;
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief Closes all the file descriptors of the pipeline except the one passed
 * as argument
 * @param p The pipeline to close the file descriptors for
 */
void	close_pipes(t_pipeline *p)
{
	t_pipeline	*current;

	current = p;
	while (current)
	{
		if (current->cmd.conn_type == CON_PIPE)
		{
			close(current->fd_in);
			close(current->fd_out);
		}
		current = current->next;
	}
}
