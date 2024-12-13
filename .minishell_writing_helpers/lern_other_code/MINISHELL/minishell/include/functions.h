/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:12:09 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/05/25 15:05:02 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/* ------------  STRUCTURES DEFINED  ---------------------------------------- */

typedef struct s_token		t_token;
typedef struct s_io_redir	t_io_redir;
typedef struct s_command	t_command;
typedef struct s_minishell	t_minishell;

/* ------------  ENUMS DEFINED  --------------------------------------------- */

typedef enum s_type			t_type;

/* ------------  FUNCTIONS DECLARED  ---------------------------------------- */

/* ========================================================================== */
/*               BUILTINS                                                     */
/* ========================================================================== */

int			cd(t_command *cmd, t_minishell *shell);

int			echo(t_command *cmd);

int			env(t_minishell *shell);

bool		is_toolong(char *str);
void		exit_minishell(t_minishell *shell, t_command *cmd);

char		**create_env(t_token *env_list);
void		export(t_minishell *shell, t_command *cmd);

int			pwd(void);

int			unset(t_minishell *shell, t_command *cmd);

/* ========================================================================== */
/*               ENVIRONMENT                                                  */
/* ========================================================================== */

t_token		*find_env(t_minishell *shell, char *new_env);
void		update_env(t_minishell *shell, char *new_env);

/* ========================================================================== */
/*               ERRORS                                                       */
/* ========================================================================== */

bool		check_error_token_list(t_minishell *shell);
void		print_error(char *error);
void		unclosed_quote_error(t_minishell *shell);

/* ========================================================================== */
/*               EXECUTION                                                    */
/* ========================================================================== */

bool		is_builtin(char *cmd);
int			execute_builtin(t_minishell *shell, t_command *cmd);

char		*get_path(char *cmd, char **envp);

void		execute(t_minishell *shell);

void		redir(t_io_redir *io);
void		redir_reset(t_io_redir *io);
void		fd_close(t_command *cmd);

void		init_pipe(t_minishell *shell);
void		setup_pipe(t_command *cmd, t_minishell *shell);
void		close_pipe(t_command *cmds, t_command *cmd);

/* ========================================================================== */
/*               FILESYSTEM                                                   */
/* ========================================================================== */

bool		check_file(t_io_redir *io);
bool		is_path(char *cmd, t_minishell *shell);
bool		is_folder(char *cmd, t_minishell *shell);

/* ========================================================================== */
/*               IO                                                           */
/* ========================================================================== */

void		handle_input(char *user_input, t_minishell *shell);
bool		is_spaces(char *user_input);

/* ========================================================================== */
/*               PARSER                                                       */
/* ========================================================================== */

char		**add_arg(char **args, char *arg);
void		init_io(t_command *cmd);
void		open_input(t_io_redir *io, char *file);
bool		delete_file(t_io_redir *io, bool input);
void		open_output(t_io_redir *io, char *file, int type);

bool		heredoc(t_io_redir *io);
void		read_heredoc(int fd, t_io_redir *io);
bool		heredoc_line(char *line, t_io_redir *io);

void		cmd_word(t_minishell *shell, t_token **token);
void		cmd_redir_in(t_minishell *shell, t_token **token);
void		cmd_redir_out(t_minishell *shell, t_token **token, int type);
void		cmd_redir_heredoc(t_minishell *shell, t_token **token);
void		cmd_pipe(t_minishell *shell, t_token **token);

char		*join_str(char *s1, char *s2, char *s3);
char		*get_key_value(char *str);
void		question_mark(t_minishell *shell, t_token *token);

void		handle_dollar(t_minishell *shell);
bool		check_heredoc_single_quote(t_token *token);
char		*get_env_value(char *key, t_minishell *shell);
char		*get_key(char *str);
void		get_dollar_value(t_token *token, t_minishell *shell);

bool		parser(t_minishell *shell);
void		create_command_list(t_minishell *shell);
void		add_command(t_minishell *shell);

void		remove_quotes(t_minishell *shell);
void		remove_empty_tokens(t_minishell *shell);
void		token_remove(t_minishell *shell, t_token *token);
char		*remove_quote(char *str, char *new);

void		give_token_type(t_minishell *shell);
bool		token_is_command(t_token *token);
bool		token_is_redir(int type);

int			redirection(char *str);
bool		ft_isspace(char c);

int			handle_quotes(char *str, t_minishell *shell);
int			count_tokens(char *str, t_minishell *shell);
int			token_len(char *str, t_minishell *shell);
char		**tokenizer(char *str, t_minishell *shell);

/* ========================================================================== */
/*               SIGNALS                                                      */
/* ========================================================================== */

void		clear_input_signal(int signal);
void		clear_input_signal_2(int signal);

/* ========================================================================== */
/*               UTILS                                                        */
/* ========================================================================== */

void		free_tokens(t_token *token);
void		free_commands(t_minishell *shell);
void		free_minishell(t_minishell *shell);

void		init_parameters(int argc, char **argv, t_minishell *shell, \
			char **envp);
t_token		*init_token_list(char **tokens);
t_command	*init_command(void);

void		check_free(void *ptr);
void		check_free_4(char *ptr1, char *ptr2, char *ptr3, char *ptr4);
void		free_matrix(char **matrix);

#endif