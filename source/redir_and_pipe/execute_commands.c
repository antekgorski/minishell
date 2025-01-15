/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:08:14 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/15 13:29:49 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int	ft_check_t(t_list *token_list, unsigned int count)
{
	t_list			*current_token;
	unsigned int	i;

	current_token = token_list;
	i = 0;
	while (current_token)
	{
		if (i == count)
			return (*(int *)current_token->content);
		current_token = current_token->next;
		i++;
	}
	return (0);
}
static int	open_file(t_minishell *minishell, unsigned int index, int flags)
{
	int	fd;

	if (!minishell->lexter_tab || !minishell->lexter_tab[index])
		ft_panic("Invalid redirection file", EXIT_FAILURE);
	fd = open(minishell->lexter_tab[index], flags, 0644);
	if (fd < 0)
		ft_panic("Error opening file", EXIT_FAILURE);
	return (fd);
}

static void	handle_token(t_minishell *minishell, t_list *c_token,
		unsigned int count)
{
	int	fd;

	if (*(int *)c_token->content == IREDIR)
	{
		fd = open_file(minishell, count - 1, O_RDONLY);
		dup2(fd, STDIN_FILENO);
	}
	else if (*(int *)c_token->content == OREDIR)
	{
		fd = open_file(minishell, count + 1, O_CREAT | O_WRONLY | O_TRUNC);
		dup2(fd, STDOUT_FILENO);
	}
	else if (*(int *)c_token->content == APPEND)
	{
		fd = open_file(minishell, count + 1, O_CREAT | O_WRONLY | O_APPEND);
		dup2(fd, STDOUT_FILENO);
	}
	close(fd);
}

void	handle_redirections(t_minishell *minishell)
{
	t_list			*c_token;
	unsigned int	count;

	c_token = minishell->token_list;
	count = 0;
	while (c_token)
	{
		if (ft_check_t(minishell->token_list, count) == CMD)
			handle_token(minishell, c_token, count);
		c_token = c_token->next;
		count++;
	}
}

// void	handle_redirections(t_minishell *minishell)
// {
// 	int				fd;
// 	t_list			*c_token;
// 	unsigned int	count;

// 	c_token = minishell->token_list;
// 	count = 0;
// 	while (c_token)
// 	{
// 		if (*(int *)c_token->content == IREDIR
// && ft_check_t(minishell->token_list,
// 				count - 1) == CMD)
// 			fd = open(minishell->lexter_tab[count - 1], O_RDONLY);
// 		else if (*(int *)c_token->content == OREDIR
// && ft_check_t(minishell->token_list,
// 				count + 1) == CMD)
// 			fd = open(minishell->lexter_tab[count + 1],
// 					O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 		else if (*(int *)c_token->content == APPEND
// && ft_check_t(minishell->token_list,
// 				count + 1) == CMD)
// 			fd = open(minishell->lexter_tab[count + 1],
// 					O_CREAT | O_WRONLY | O_APPEND, 0644);
// 		if (fd < 0)
// 			ft_panic("minishell", EXIT_FAILURE);
// 		if (*(int *)c_token->content == IREDIR)
// 			dup2(fd, STDIN_FILENO);
// 		else
// 			dup2(fd, STDOUT_FILENO);
// 		close(fd);
// 		c_token = c_token->next;
// 	}
// }

// void	execute_commands(t_cmd *cmd_list, t_minishell *minishell)
// {
// 	int fd_in = STDIN_FILENO;
// 	int fd[2];
// 	pid_t pid;
// 	t_cmd *cmd = cmd_list;

// 	while (cmd)
// 	{
// 		if (cmd->next)
// 		{
// 			if (pipe(fd) == -1)
// 				ft_panic("pipe failed", 1);
// 		}

// 		pid = fork();
// 		if (pid == 0)
// 		{
// 			// Child process
// 			if (cmd->infile)
// 			{
// 				fd_in = open(cmd->infile, O_RDONLY);
// 				if (fd_in < 0)
// 				{
// 					perror("open infile");
// 					exit(EXIT_FAILURE);
// 				}
// 				dup2(fd_in, STDIN_FILENO);
// 				close(fd_in);
// 			}
// 			else if (fd_in != STDIN_FILENO)
// 			{
// 				dup2(fd_in, STDIN_FILENO);
// 				close(fd_in);
// 			}

// 			if (cmd->outfile)
// 			{
// 				int flags = O_WRONLY | O_CREAT;
// 				if (cmd->append)
// 					flags |= O_APPEND;
// 				else
// 					flags |= O_TRUNC;
// 				int fd_out = open(cmd->outfile, flags, 0644);
// 				if (fd_out < 0)
// 				{
// 					perror("open outfile");
// 					exit(EXIT_FAILURE);
// 				}
// 				dup2(fd_out, STDOUT_FILENO);
// 				close(fd_out);
// 			}
// 			else if (cmd->next)
// 			{
// 				dup2(fd[1], STDOUT_FILENO);
// 				close(fd[1]);
// 			}

// 			if (cmd->next)
// 				close(fd[0]);
// 			// Być może da się to usprawnić !?!?!?
// 			int builtin_status = e_bild(cmd->cmd, minishell);
// 			if (builtin_status == 0)
// 				execute_external(cmd->cmd, minishell);
// 			else
// 				exit(builtin_status);
// 			exit(minishell->f_signal);
// 		}
// 		else if (pid < 0)
// 			ft_panic("fork failed", 1);
// 		else
// 		{
// 			// Parent ptocess
// 			waitpid(pid, &minishell->f_signal, 0);
// 			if (fd_in != STDIN_FILENO)
// 				close(fd_in);
// 			if (cmd->next)
// 			{
// 				close(fd[1]);
// 				fd_in = fd[0];
// 			}
// 		}
// 		cmd = cmd->next;
// 	}
// }
