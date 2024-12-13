/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:21:38 by mjakowic          #+#    #+#             */
/*   Updated: 2024/08/08 19:11:36 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../libs/libft/libft.h"
# include "lexing.h"
# include "parsing.h"
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/wait.h>
# include <termios.h>

# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif

# ifndef ECHOCTL
#  define ECHOCTL 0001000
# endif

typedef enum e_err_no
{
	ENO_SUCCESS,
	ENO_GENERAL,
	ENO_CANT_EXEC = 126,
	ENO_NOT_FOUND,
	ENO_EXEC_255 = 255
}					t_err_no;

typedef enum e_err_msg
{
	ERRMSG_CMD_NOT_FOUND,
	ERRMSG_NO_SUCH_FILE,
	ERRMSG_PERM_DENIED,
	ERRMSG_AMBIGUOUS,
	ERRMSG_TOO_MANY_ARGS,
	ERRMSG_NUMERIC_REQUI
}					t_err_msg;

typedef struct s_err
{
	t_err_no		no;
	t_err_msg		msg;
	char			*cause;
}					t_err;

typedef struct s_path
{
	t_err			err;
	char			*path;
}					t_path;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_signals
{
	bool			signint_child;
	bool			heredoc_sigint;
}					t_singals;

typedef struct s_content
{
	char			*line;
	char			**envir;
	t_token			*tokens;
	t_token			*free_token;
	int				exit_state;
	t_node			*parsed;
	t_parse_error	parse_error;
	t_env			*enviroment;
	int				stdin;
	int				stdout;
	int				error;
	struct termios	terminal;
}					t_content;

extern t_singals	g_signal;

t_token				*ft_tokens(t_content *minishell);
t_token				*ft_tokens_handle(char *line, t_content *minishell);
t_node				*ft_parse(t_content *minishell);
t_node				*ft_start_parse(t_content *minishell);
t_node				*ft_check_and_comb(t_content *minishell);
t_node				*ft_combine(t_node *left, t_node_type operator,
						t_node	*right, t_content *minishell);
t_io_type			ft_get_io_type(t_token_type type);
void				ft_get_next_token(t_content *minishell);
int					ft_is_redirector(t_token_type type);
t_node				*ft_get_text_command(t_content *minishell);
t_node				*get_new_node(t_node_type type);
t_io_node			*ft_add_io_node(t_token_type type, char *value);
void				ft_connect_io_node(t_io_node **nodes, t_io_node *new);
t_io_node			*ft_add_io_node(t_token_type type, char *value);
bool				check_for_pipe_and_token(t_content *minishell);
void				ft_update_env_list(char *key, char *value, bool yes,
						t_content *minishell);
void				ft_init_env(t_content *minishell);
void				ft_init_tree(t_content *minishell, t_node *node);
char				*ft_strjoin_f(char *s1, char *s2);
char				*ft_get_envlst_val(char *key, t_content *minishell);
char				*ft_handle_dollar(char *str, int *i, t_content *minishell);
char				**ft_expand(char *str, t_content *minishell);
bool				ft_is_valid_var_char(char c);
char				*ft_normal_string(char *str, int *i);
char				*ft_handle_doubqoute(char *str, int *i,
						t_content *minishell);
char				*ft_clean_empy_str(char *str);
void				ft_sigquit_handler(int num);
bool				ft_is_delimiter(char *delimiter, char *str);
void				ft_heredoc_expander(char *str, int fd,
						t_content *minishell);
char				**ft_expander_split(char const *s);
char				*ft_strip_quotes(char *str);
void				ft_init_signals(t_content *minishell);
int					md_pwd(void);
int					md_echo(char **as);
int					md_env(t_content *minishell);
int					md_cd(char *path, t_content *minishell);
int					md_unset(t_content *minishell, char **args);
void				md_exit(t_content *minishell);
int					md_export(char **argv, t_content *minishell);
t_err				ft_check_exec(char *file, bool cmd);
int					ft_check_redirection(t_node *node);
void				ft_reset_stds(bool is_piped, t_content *minishell);
int					ft_exec_simple_cmd(t_node *node, bool is_piped,
						t_content *minishell);
t_path				ft_get_path(char *cmd, t_content *minishell);
bool				ft_is_builtin(char *arg);
int					ft_exec_builtin(char **args, t_content *minishell);
t_err				ft_check_write(char *file);
t_err				ft_check_read(char *file);
int					ft_out(t_io_node *io_list, int *status);
int					ft_in(t_io_node *io_list, int *status);
int					ft_append(t_io_node *io_list, int *status);
int					ft_err_msg(t_err err);
int					ft_get_exit_status(int status);
int					ft_exec_node(t_node *tree, bool is_piped,
						t_content *minishell);
void				ft_clear_parse(t_node **parse, t_content *minishell);
void				ft_recursive_clear_parse(t_node *node);
void				ft_clear_cmd_node(t_node *node);
void				ft_clear_io_list(t_io_node **lst);
void				ft_clean_ms(t_content *minishell);
void				ft_heredoc(t_io_node *io, int p[2], t_content *minishell);
void				*gc_collector(void *list, bool free);
char				*ft_extract_key(char *str);
char				*ft_extract_value(char *str);
bool				ft_env_entry_exists(char *key, t_content *minishell);
void				ft_ex_parse_err(t_content *minishell);
void				ft_parse_err(t_parse_err type, t_content *minishell);
void				ft_clear_envlist(t_content *minishell);
#endif
