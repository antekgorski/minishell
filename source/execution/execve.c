/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/19 16:24:57 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

// int	is_builtin_no_fork(const char *cmd)
// {
// 	if (ft_strcmp(cmd, "cd") == 0 ||
// 		ft_strcmp(cmd, "export") == 0 ||
// 		ft_strcmp(cmd, "unset") == 0 ||
// 		ft_strcmp(cmd, "exit") == 0)
//         return (1);
//     return (0);
// }

// int execute_external(char	**args, t_minishell *minishell)
// {
// 	// gdy jest pipe
// 	if (minishell->cmd_list->next)
// 		return (execute_pipeline(minishell));
// 	else
// 	{
// 		// sprawdza czy builtin powinien działać w procesie macierzystym
// 		if (is_builtin_no_fork(args[0]))
// 			return (e_bild(args, minishell));
// 		//gdy to zwykła komenda
// 		pid_t pid = fork();
// 		if (pid < 0)
// 		{
// 			perror("fork");
// 			return (1);
// 		}
// 		if (pid == 0)
// 		{
// 			handle_redirections(minishell);
// 			if (minishell->cmd_list->is_builtin)
// 			{
// 				minishell->f_signal = e_bild(args, minishell);
// 				exit(minishell->f_signal);
// 			}
// 			else
// 			{
// 				execute_child_process(args, minishell);
// 				exit(minishell->f_signal);
// 			}
// 		}
// 		else
// 		{
// 			int status;
// 			waitpid(pid, &status, 0);
// 			if (WIFEXITED(status))
// 				return (WEXITSTATUS(status));
// 			else if (WIFSIGNALED(status))
// 				return (128 + WTERMSIG(status));
// 		}
// 	}
// 	return(0);

// }

// opcja w której builtinsy działają w procesie potomnym.
// int	execute_external(char **args, t_minishell *minishell)
// {
// 	if (!minishell->cmd_list->next)
// 	{
// 		pid_t pid = fork();
// 		if (pid < 0)
// 		{
// 			perror("fork");
// 			return (1);
// 		}
// 		if (pid == 0)
// 		{
// 			handle_redirections(minishell);
// 			if (minishell->cmd_list->is_builtin)
// 			{
// 				e_bild(args, minishell);
// 				exit(minishell->f_signal);
// 			}
// 			else
// 			{
// 				execute_child_process(args, minishell);
// 				exit(minishell->f_signal);
// 			}
// 		}
// 		else
// 		{
// 			int	status;
// 			waitpid(pid, &status, 0);
// 			if (WIFEXITED(status))
// 				return (WEXITSTATUS(status));
// 			else if (WIFSIGNALED(status))
// 				return (128 + WTERMSIG(status));
// 		}
// 	}
// 	else
// 	{
// 		return (execute_pipeline(minishell));
// 	}
// 	return (0);
// }

// First version
// // Funkcja wykonująca polecenie zewnętrzne w nowym procesie
int	execute_external(char **args, t_minishell *minishell)
{
	pid_t	pid;
	int		status;

	// handle_redirections(minishell);
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
		execute_child_process(args, minishell);
	else
		status = wait_for_child_process(pid);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (0);
}
