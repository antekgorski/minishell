/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:59:24 by fursini           #+#    #+#             */
/*   Updated: 2024/05/20 17:33:06 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**add_arg(char **args, char *arg)
{
	char	**new;
	int		i;

	i = 0;
	while (args && args[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (args && args[i])
	{
		new[i] = ft_strdup(args[i]);
		check_free(args[i]);
		i++;
	}
	new[i] = ft_strdup(arg);
	new[i + 1] = NULL;
	check_free(args);
	return (new);
}

void	init_io(t_command *cmd)
{
	if (!cmd->io_redir)
	{
		cmd->io_redir = malloc(sizeof(t_io_redir));
		if (!cmd->io_redir)
			return ;
		cmd->io_redir->input = NULL;
		cmd->io_redir->output = NULL;
		cmd->io_redir->heredoc = NULL;
		cmd->io_redir->fd_input = -1;
		cmd->io_redir->fd_output = -1;
		cmd->io_redir->stdinput = -1;
		cmd->io_redir->stdoutput = -1;
	}
}

void	open_input(t_io_redir *io, char *file)
{
	if (!delete_file(io, true))
		return ;
	io->input = ft_strdup(file);
	if (io->input && io->input[0] == '\0')
	{
		print_error(strerror(errno));
		return ;
	}
	io->fd_input = open(io->input, O_RDONLY);
	if (io->fd_input == -1)
	{
		g_exit_status = 1;
		print_error(strerror(errno));
	}
}

bool	delete_file(t_io_redir *io, bool input)
{
	if (io->input && input)
	{
		if (io->fd_input == -1 || (io->output && io->fd_output == -1))
			return (false);
		if (io->heredoc)
		{
			check_free(io->heredoc);
			io->heredoc = NULL;
			unlink(io->input);
		}
		check_free(io->input);
		io->input = NULL;
		close(io->fd_input);
	}
	else if (io->output && !input)
	{
		if (io->fd_output == -1 || (io->input && io->fd_input == -1))
			return (false);
		check_free(io->output);
		io->output = NULL;
		close(io->fd_output);
	}
	return (true);
}

void	open_output(t_io_redir *io, char *file, int type)
{
	if (!delete_file(io, false))
		return ;
	io->output = ft_strdup(file);
	if (io->output && io->output[0] == '\0')
	{
		print_error(strerror(errno));
		return ;
	}
	if (type == REDIR_OUT)
		io->fd_output = open(io->output, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	else if (type == APPEND)
		io->fd_output = open(io->output, O_WRONLY | O_CREAT | O_APPEND, 0664);
	if (io->fd_output == -1)
	{
		g_exit_status = 1;
		print_error(strerror(errno));
	}
}
