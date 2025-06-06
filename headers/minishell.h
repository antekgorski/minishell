/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:36:02 by agorski           #+#    #+#             */
/*   Updated: 2025/01/30 18:55:34 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// my includes
# include "../libft/libft.h"
# include "structs.h"

// system includes
# include <errno.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <termios.h>

# define SYMBOLS_D "|<>\"\' \t"
# define SYMBOLS_C "|<> \t\0"
# define SYMBOLS_R "$ \t\0"
# define SYMBOLS_RR "$ \'\t\0"
# define SYMBOLS_S "$?\0"
# define SYM_E " \t"

// main functions

void	main_loop(t_minishell *minishell);
void	minishell_init(t_minishell *minishell, char **envp);
void	env_start(t_minishell *minishell, char **envp);
void	welcome(void);

// lexer functions

char	*ft_d_roll(char *line, t_minishell *minishell);
void	ft_dolar_case1(t_t *t, t_minishell *minishell);
void	ft_dolar_case2(t_t *t);
void	ft_dolar_case3(t_t *t);
void	ft_dolar_case4(t_t *t, char *line, t_minishell *minishell);
void	ft_dolar_case5(t_t *t, char *line);
void	ft_init_dolar(t_t *dolar);
int		ft_squote(char *temp_line, t_minishell *minishell);
int		ft_dquote(char *temp_line, t_minishell *minishell);
int		ft_dolar(char *temp_line, t_minishell *minishell);
int		ft_pipe(t_minishell *minishell);
int		ft_comend(char *temp_line, t_minishell *minishell);
int		ft_oredir(char *temp_line, t_minishell *minishell);
int		ft_iredir(char *temp_line, t_minishell *minishell);
int		ft_append(char *temp_line, t_minishell *minishell);
int		check_quote(char *line);
void	ft_quote_loop(char *line, t_q *q);
void	ft_init_dolar(t_t *dolar);

// parser functions

char	**ft_addline(t_minishell *minishell, char *line, t_token token);
void	parse(t_minishell *minishell);
void	ft_lexter(t_minishell *minishell);
char	*ft_get_env(t_list *head, char *key);
t_list	*ft_find_env(t_list *head, char *key);
void	ft_get_token(t_token token, t_minishell *minishell);
void	ft_cmd_bilder(t_minishell *minishell);
bool	ft_check_redir(t_list *token);
void	ft_t_cmd_init(t_cmd *cmd);
void	ft_cb_init(t_cb *cb, t_minishell *minishell);
t_cmd	*ft_new_cmd(void);
void	ft_add_redir(t_redir **redirs, t_token token, char *file);
char	**ft_add_cmd(char **argv, char *line);
bool	ft_cmd_redir(t_minishell *minishell, t_cb *cb, t_token *redir_type);

// error handler

void	ft_panic(char *message, int is_error);
void	reset_prompt(void);
void	syntax_error(char *message, t_minishell *minishell);

// free function

void	ft_shell_free(t_minishell *minishell);
void	tab_free(char ***lexter_tab);
void	env_free(t_list *env);
void	ft_token_free(t_list **token_list);
void	ft_free_cmd_list(t_cmd **cmd_ptr);

// Signals

void	signal_initialization(void);
void	signal_initialization_child(void);
void	handle_input(char *input, t_minishell *minishell);

// Builtins

int		ft_strcmp(const char *s1, const char *s2);
int		e_bild(char **args, t_minishell *minishell);
int		ft_pwd(void);
int		ft_cd(char **args, t_minishell *minishell);
int		ft_echo(char **args);
int		ft_env(t_minishell *minishell);
int		ft_exit(t_minishell *minishell);
int		ft_unset(t_minishell *minishell, char **name);
int		ft_export(t_minishell *minishell, char **args);
int		prepare_env_split(t_minishell *minishell, char *arg, char ***split);
void	ft_free_split(char **split);
int		is_valid_key(char *key);
int		ft_print_env(t_minishell *minishell);

// env

char	**ft_split_env(char *env);
void	env_start(t_minishell *minishell, char **envp);
char	*ft_get_env(t_list *head, char *key);
t_list	*ft_find_env(t_list *head, char *key);

// execve
int		execute_external(char **args, t_minishell *minishell, t_cmd *cmd);
int		execute_child_process(char **args, t_minishell *minishell);
int		wait_for_child_process(pid_t pid);
void	ft_free_split2(char ***split);
char	*ft_strjoin_free(char *s1, char *s2);
char	*find_executable(char *command, char **envp);
void	execute(t_cmd *cmds, t_minishell *minishell);
char	**list_to_envp(t_list *env);
int		handle_heredoc(const char *delimiter);
void	handle_redirections(t_redir *redirs);
int		is_builtin(t_cmd *cmd);
pid_t	run_proces(t_cmd *cmd, int in_fd, int out_fd, t_minishell *minishell);
void	handle_heredocs(t_redir *redirs);
void	handle_other_redirections(t_redir *redirs);
char	*handle_full_path(char *command, char *exec_path);
int		has_input_redirection(t_redir *redirs);
int		has_output_redirection(t_redir *redirs);
int		validate_redirections(t_redir *redirs, t_minishell *minishell);
int		validate_pipeline(t_cmd *cmds, t_minishell *minishell);
char	*get_executable_path(char *arg, char **envp);
void	check_path_is_dir(char *exec_path, char **envp, t_minishell *minishell);
void	handle_execve_error(char *exec_path, char **envp);
char	*ft_strtok(char *str, const char *delim);
void	handle_command_not_found(char **args, char **envp,
			t_minishell *minishell);
void	clean_and_free(char *exec_path, char **envp, t_minishell *minishell,
			int exit_code);
void	print_error_message(char *arg, char *error_message);
int		check_redirection_access(t_cmd *cmd, t_minishell *minishell);
int		check_pipeline_redirections(t_cmd *cmds, t_minishell *minishell);

#endif
