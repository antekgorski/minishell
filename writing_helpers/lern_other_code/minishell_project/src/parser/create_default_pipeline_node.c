/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_default_pipeline_node.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:29:11 by sehosaf           #+#    #+#             */
/*   Updated: 2024/07/17 09:29:18 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_pipeline	*create_default_pipeline_node(void)
{
	t_pipeline	*res;

	res = malloc(sizeof(t_pipeline));
	if (!res)
		return (NULL);
	res->next = NULL;
	res->prev = NULL;
	res->fd_in = 0;
	res->fd_out = 1;
	res->cmd.args = NULL;
	res->cmd.conn_type = CON_NONE;
	res->cmd.is_heredoc = 0;
	res->cmd.limiter = NULL;
	res->cmd.infile = NULL;
	res->cmd.outfile = NULL;
	res->cmd.ap_mode = 0;
	return (res);
}
