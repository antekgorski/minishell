/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:36:02 by agorski           #+#    #+#             */
/*   Updated: 2025/01/13 12:24:48 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// my includes
# include "../libft/libft.h"
# include "structs.h"

// system includes
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <termios.h>

# define SYMBOLS_D "|<>\"\' \t"
# define SYMBOLS_C "|<> \t\0"
# define SYMBOLS_R "$ \t\0"
# define SYMBOLS_S "$?\0"
# define SYM_E " \t"

// main functions

void	main_loop(t_minishell *minishell);
void	minishell_init(t_minishell *minishell, char **envp);
void	env_start(t_minishell *minishell, char **envp);

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

// error handler

void	ft_panic(char *message, int is_error);
void	reset_prompt(void);
void	syntax_error(char *message, t_minishell *minishell);

// free function

void	ft_shell_free(t_minishell *minishell);
void	tab_free(char ***lexter_tab);
void	env_free(t_list *env);
void	ft_token_free(t_list **token_list);

// Signals

void	signal_initialization(void);
void	handle_input(char *input, t_minishell *minishell);

// Builtins

int		ft_strcmp(const char *s1, const char *s2);
int		e_bild(char **args, t_minishell *minishell);
int		ft_pwd(void);
int		ft_cd(char **args, t_minishell *minishell);
int		ft_echo(char **args);
int		ft_env(t_minishell *minishell);
int		ft_exit(t_minishell *minishell);
// int		ft_unset(t_minishell *minishell, const char *name);
int		ft_unset(t_minishell *minishell, char **name);
int		ft_export(t_minishell *minishell, char **args);
int		ft_print_env(t_minishell *minishell);

// env

char	**ft_split_env(char *env);
void	env_start(t_minishell *minishell, char **envp);
char	*ft_get_env(t_list *head, char *key);
t_list	*ft_find__env(t_list *head, char *key);

// execve
int		execute_external(char **args, t_minishell *minishell);
void	execute_child_process(char **args, t_minishell *minishell);
int		wait_for_child_process(pid_t pid);
void	ft_free_split2(char ***split);
char	*ft_strjoin_free(char *s1, char *s2);
char	*find_executable(char *command, char **envp);

// redirections and pipes
t_cmd	*parse_tokens(t_minishell *minishell);
void	execute_commands(t_cmd *cmd_list, t_minishell *minishell);

#endif
