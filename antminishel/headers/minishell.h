/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:36:02 by agorski           #+#    #+#             */
/*   Updated: 2024/12/20 18:09:14 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// my includes
# include "../libft/libft.h"
# include <readline/history.h>

// system includes
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>

# define PROMPT "antpaw$"
# define SYMBOLS "'|''<''>''\"''\'''''$'' ''\t'"

// struct enum for tokens used in parser

typedef enum e_token
{
	DQUOTE,
	SQUOTE,
	DOLAR,
	PIPE,
	IREDIR,
	OREDIR,
	APPEND,
	HERDOC,
	CMD
}					t_token;

// main struct for minishell

typedef struct s_minishell
{
	char			*line;
	char			**lexter_tab;
	t_token			*token;
	t_list			*token_list;
	t_list			*m_env;
	int				f_signal;

}					t_minishell;

// struct for linked list duble or single?

typedef struct s_node
{
	t_token			token;
	char			**command;
	struct s_node	*prev;
	struct s_node	*next;

}					t_node;

// main functions
void				main_loop(t_minishell *minishell);
void				minishell_init(t_minishell *minishell, char **envp);
void				env_start(t_minishell *minishell, char **envp);

// lexer functions
int					ft_squote(char *temp_line, t_minishell *minishell);
int					ft_dquote(char *temp_line, t_minishell *minishell);
int					ft_dolar(char *temp_line, t_minishell *minishell);
int					ft_pipe(t_minishell *minishell);
int					ft_comend(char *temp_line, t_minishell *minishell);
int					ft_oredir(char *temp_line, t_minishell *minishell);
int					ft_iredir(char *temp_line, t_minishell *minishell);
int					ft_append(char *temp_line, t_minishell *minishell);
int					ft_heredoc(char *temp_line, t_minishell *minishell);
char				**ft_addline(t_minishell *minishell, char *line,
						t_token token);

// parser functions
void				parse(t_minishell *minishell);
int					check_quote(t_minishell *minishell);
void				ft_lexter(t_minishell *minishell);
char				*ft_get_env(t_list *head, char *key);
t_list				*ft_find_env(t_list *head, char *key);
void				ft_get_token(t_token token, t_minishell *minishell);

// error handler
void				ft_panic(char *message, int is_error);
void				reset_prompt(void);
void				syntax_error(char *message, t_minishell *minishell);

// free function
void				ft_shell_free(t_minishell *minishell);
void				tab_free(char ***lexter_tab);
void				env_free(t_list *env);
void				ft_token_free(t_list **token_list);

// Signals
void				signal_initialization(void);
void				handle_input(char *input, t_minishell *minishell);

// Builtins
int					ft_strcmp(const char *s1, const char *s2);
int					e_bild(char **args, t_minishell *minishell);
int					ft_pwd(void);
int					ft_cd(char **args);
int					ft_echo(char **args);
int					ft_env(t_minishell *minishell);
int					ft_exit(t_minishell *minishell);
int					ft_unset(t_minishell *minishell, const char *name);
int					ft_export(t_minishell *minishell, char **args);

// env
char				**ft_split_env(char *env);
void				env_start(t_minishell *minishell, char **envp);
char				*ft_get_env(t_list *head, char *key);
t_list				*ft_find_env(t_list *head, char *key);

#endif
