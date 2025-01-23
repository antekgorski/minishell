/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/19 15:20:20 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

// int	execute_pipeline(t_minishell *minishell)
// {
// 	t_cmd	*current_cmd;
// 	int	pipefd[2];
// 	int	prev_fd = -1;
// 	int status;
// 	pid_t	pid;
// 	// int cmd_num = 1;


// 	current_cmd = minishell->cmd_list;
// 	// Wyświetl listę komend przed rozpoczęciem potoków
//     printf("Executing Pipeline:\n");
//     ft_parser_test(minishell);

// 	while(current_cmd)
// 	{
// 		// printf("Executing Command %d: %s\n", cmd_num, current_cmd->cmd[0]);
//         // cmd_num++;
// 		if (current_cmd->next)
// 		{
// 			if (pipe(pipefd) < 0)
// 			{
// 				perror("pipe");
// 				return (1);
// 			}
// 		}
// 		pid = fork();
// 		if (pid < 0)
// 		{
// 			perror("fork");
// 			return (1);
// 		}

// 		if (pid == 0)
// 		{
// 			//child process
// 			if (prev_fd != -1)
// 			{
// 				dup2(prev_fd, STDIN_FILENO);
// 				close(prev_fd);
// 			}

// 			if (current_cmd->next)
// 			{
// 				dup2(pipefd[1], STDOUT_FILENO);
// 				close(pipefd[0]);
// 				close(pipefd[1]);
// 			}

// 			handle_redirections(minishell);

// 			if (current_cmd->is_builtin)
// 			{
// 				minishell->f_signal = e_bild(current_cmd->cmd, minishell);
// 				exit(minishell->f_signal);
// 			}
// 			else
// 			{
// 				execute_child_process(current_cmd->cmd,minishell);
// 				exit(minishell->f_signal);
// 			}
// 		}
// 		else
// 		{
// 			//parent process
// 			if (prev_fd != -1)
// 				close(prev_fd);
// 			if (current_cmd->next)
// 			{
// 				close(pipefd[1]);
// 				prev_fd = pipefd[0];
// 			}
// 			current_cmd = current_cmd->next;
// 		}
// 	}
// 	if (prev_fd != -1)
// 		close(prev_fd);
// 	while(wait(&status) > 0)
// 	{
// 		if (WIFEXITED(status))
// 			return (WEXITSTATUS(status));
// 		else if (WIFSIGNALED(status))
// 			return (128 + WTERMSIG(status));
// 	}
// 	return (0);
// }
