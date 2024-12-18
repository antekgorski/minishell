/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:36:02 by agorski           #+#    #+#             */
/*   Updated: 2024/12/18 13:29:17 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>

# define PROMPT "antpaw$"
# define SYMBOLS "'|''<''>''\"''\'''''$'' ''\t'"

// main struct for minishell

typedef struct s_minishell
{
	char			*line;
	char			**lexter_tab;
}					t_minishell;

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
	CMD,
	TO_PARSE
}					t_token;

// struct for linked list duble or lingle?

typedef struct s_node
{
	t_token			token;
	char			**command;
	struct s_node	*prev;
	struct s_node	*next;

}					t_node;

// main functions
void				main_loop(t_minishell *minishell);

// lexer functions
void				ft_lexter(t_minishell *minishell);
int					ft_squote(char *temp_line, t_minishell *minishell);
int					ft_dquote(char *temp_line, t_minishell *minishell);
int					ft_dolar(char *temp_line, t_minishell *minishell);
int					ft_pipe(t_minishell *minishell);
int					ft_comend(char *temp_line, t_minishell *minishell);
int					ft_oredir(char *temp_line, t_minishell *minishell);
int					ft_iredir(char *temp_line, t_minishell *minishell);
int					ft_append(char *temp_line, t_minishell *minishell);
int					ft_heredoc(char *temp_line, t_minishell *minishell);
char				**ft_addline(char **argv, char *line);

// parser functions
void				parse(t_minishell *minishell);
int					check_quote(t_minishell *minishell);

// error handler
void				ft_panic(char *message, int is_error);
void				reset_prompt(void);
void				syntax_error(char *message, t_minishell *minishell);

// free function
void				ft_shell_free(t_minishell *minishell);
void				tab_free(char **lexter_tab);

// Signals
void				signal_initialization(void);
void				handle_input(char *input);

#endif
