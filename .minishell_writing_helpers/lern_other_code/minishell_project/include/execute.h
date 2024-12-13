/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <dmoroz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:18:00 by sehosaf           #+#    #+#             */
/*   Updated: 2024/08/01 18:17:12 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "minishell.h"
# include "libft.h"
# include "environment.h"

# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif

//		** execute builtin **
bool	is_builtin(t_command command);
int		execute_builtin(t_command command, t_shell *shell);

//		** execute utils **
char	**env_list_to_array(t_env *env);
char	*find_sys_cmd(char *cmd, t_env *env);
bool	is_async(t_pipeline *pipeline);
bool	should_execute(t_connection conn_type, int exit_status);

//		** execute command **
int		exec_command(t_shell *shell, t_pipeline *p, t_pipeline *cur, pid_t pid);
pid_t	create_child(t_shell *shell, t_pipeline *p, t_pipeline *cur);
void	exec_pipeline(t_shell *shell, int num_cmds);
void	wait_for_child_process(t_shell *shell, pid_t pid);

//		** builtin functions **
int		cmd_cd(t_shell *shell, char **args);
int		cmd_echo(const char **args);
int		cmd_env(t_shell *shell);
int		cmd_exit(t_shell *shell, char **args, t_connection ct);
int		cmd_export(t_shell *shell, const char *key_value);
int		cmd_pwd(void);
int		cmd_unset(t_shell *shell, const char *key);

//		** redirection **
int		create_pipes(t_pipeline *pipeline);
void	close_pipes(t_pipeline *p);

#endif
