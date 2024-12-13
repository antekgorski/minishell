/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:37:44 by sehosaf           #+#    #+#             */
/*   Updated: 2024/08/01 18:40:39 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <bits/waitflags.h>
# include <dirent.h>
# include <errno.h>
# include <stdbool.h>
# include <limits.h>
# include "libft.h"
# include "messages.h"

/*
t_command struct represent command which has to be executed
Fields:
	args (char **) - command name/path and it's arguments
	connection_type (char *) - the way commend is connected to previous one;
	possible types: "|" - pipe, "&&" - and operator, "||" -
	or operator, NULL - first command
	is_heredoc (int) - flag, True if input redirection has to be from here_doc
	limiter (char *) - limiter string for here_doc
	infile (char *) - file name of redirected input source,
	if should be; NULL otherwise
	outfile (char *) - file name of redirected output,
	if should be; NULL otherwise
	outfile_append_mode (int) - flag,
	True if output redirection has to be in append mode;
	ignore if outfile is NULL
*/

typedef enum e_connection
{
	CON_NONE,
	CON_PIPE,
	CON_OR,
	CON_AND
}	t_connection;

typedef struct s_command
{
	char			**args;
	t_connection	conn_type;
	int				is_heredoc;
	char			*limiter;
	char			*infile;
	char			*outfile;
	int				ap_mode;
}	t_command;

typedef struct s_pipeline
{
	t_command			cmd;
	struct s_pipeline	*next;
	struct s_pipeline	*prev;
	int					fd_in;
	int					fd_out;
}	t_pipeline;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_shell
{
	t_env	*env;
	int		exit_status;
}	t_shell;

# define MAX_CMD 1024

t_pipeline	*parse(char *line, t_shell *shell);
int			init_environment(t_shell *shell);
void		execute(t_pipeline *pipeline, t_shell *shell);

//			** utility functions **
void		cleanup_and_exit_shell(t_shell *shell);
long		ft_atol(const char *str);
void		free_split(char **split);
int			get_split_size(char **split);
int			ft_isspace(int c);
int			validate_pipeline(t_pipeline *p);
void		free_pipeline(t_pipeline *p);

//			** signal handlers **
void		interactive_signal_handlers(void);
void		non_interactive_signal_handlers(void);

#endif
