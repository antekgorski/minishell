/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:57:19 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/05/24 18:40:15 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

/* ------------  ENUMS DEFINED  --------------------------------------------- */

/**
 * @brief Enum for different types of shell command components or operations.
 *
 * @details
 * - `EMPTY` represents an empty command or argument.
 * - `APPEND` represents an append operation in a command.
 * - `PIPE` represents a pipe operation in a command.
 * - `COMMAND` represents a command.
 * - `ARGUMENT` represents an argument to a command.
 * - `HEREDOC` represents a heredoc operation in a command.
 * - `REDIR_IN` represents input redirection in a command.
 * - `REDIR_OUT` represents output redirection in a command.
 */
typedef enum s_type
{
	EMPTY = 0,
	APPEND = 1,
	PIPE = 2,
	COMMAND = 3,
	ARGUMENT = 4,
	HEREDOC = 5,
	REDIR_IN = 6,
	REDIR_OUT = 7,
}				t_type;

/* ------------  STRUCTURES DEFINED  ---------------------------------------- */

/**
 * @brief Struct representing a token in a shell command.
 * 
 * @details
 * - `str` is the string representation of the token.
 * - `type` is the type of the token, represented as an integer.
 * - `next` is a pointer to the next token in a linked list of tokens.
 * - `prev` is a pointer to the previous token in a linked list of tokens.
 */
typedef struct s_token
{
	char			*str;
	int				type;
	struct s_token	*next;
	struct s_token	*prev;
}				t_token;

/**
 * @brief Struct representing I/O redirection in a shell command.
 * 
  * @details
 * - `input` is the input file for redirection.
 * - `output` is the output file for redirection.
 * - `heredoc` is the heredoc string for redirection.
 * - `fd_input` is the file descriptor for input redirection.
 * - `fd_output` is the file descriptor for output redirection.
 * - `stdinput` is the standard input file descriptor.
 * - `stdoutput` is the standard output file descriptor.
 */
typedef struct s_io_redir
{
	char	*input;
	char	*output;
	char	*heredoc;
	int		fd_input;
	int		fd_output;
	int		stdinput;
	int		stdoutput;
}				t_io_redir;

/**
 * @brief Struct representing a shell command.
 *
 * @details
 * - `name` is the name of the command.
 * - `args` is a null-terminated array of arguments to the command.
 * - `pipe` is a boolean indicating whether the command is part of 
 * a pipe operation.
 * - `fd_pipe` is a pointer to a file descriptor used for pipe operations.
 * - `io_redir` is a pointer to a struct representing I/O redirection for 
 * the command.
 * - `next` is a pointer to the next command in a linked list of commands.
 * - `prev` is a pointer to the previous command in a linked list of commands.
 */
typedef struct s_command
{
	char				*name;
	char				**args;
	bool				pipe;
	int					*fd_pipe;
	t_io_redir			*io_redir;
	struct s_command	*next;
	struct s_command	*prev;
}				t_command;

/**
 * @brief Struct representing the state of a minishell session.
 *
 * @details
 * - `envp` is a null-terminated array of environment variables.
 * - `token_list` is a pointer to a linked list of tokens parsed from 
 * the command line.
 * - `env_list` is a pointer to a linked list of environment variables.
 * - `command` is a pointer to a struct representing the current command 
 * being processed.
 */
typedef struct s_minishell
{
	char		**envp;
	t_token		*token_list;
	t_token		*env_list;
	t_command	*command;
}				t_minishell;

#endif