/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:57:01 by agorski           #+#    #+#             */
/*   Updated: 2025/01/23 14:18:34 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCTS_H
# define STRUCTS_H

/**
 * @brief struct enum for tokens used in parser
 * @param CMD =0
 * @param PIPE =1
 * @param IREDIR =2
 * @param OREDIR =3
 * @param APPEND =4
 * @param HERDOC =5
 */
typedef enum e_token
{
	CMD,
	PIPE,
	IREDIR,
	OREDIR,
	APPEND,
	HERDOC
}					t_token;

/**
 * @brief struct for redirection
 * @param t_token type
 * @param char *filename
 */
typedef struct s_redir
{
	t_token			type;
	char			*filename;
	struct s_redir	*next;
}					t_redir;

/**
 * @brief struct for command
 * @param char **cmd
 * @param t_redir *redirs
 * @param int infile_fd
 * @param int outfile_fd
 * @param int is_builtin
 *
 */
typedef struct s_cmd
{
	char			**argv;
	t_redir			*redirs;
	struct s_cmd	*next;
}					t_cmd;

/**
 * @brief main struct for minishell
 * @param char *line
 * @param char **lexter_tab
 * @param t_token *token
 * @param t_list *token_list
 * @param t_list *m_env
 * @param int f_signal
 */
typedef struct s_minishell
{
	char			*line;
	char			**lexter_tab;
	t_list			*token_list;
	t_list			*m_env;
	int				f_signal;
	char			*l_hdr;
	t_cmd			*cmd_list;

}					t_minishell;

// steuct for dolar rollup
typedef struct s_t
{
	int				start;
	int				end;
	char			*result;
	char			*temp;
	char			*env;
}					t_t;

// struct for quote_check
typedef struct s_q
{
	int				result;
	int				i;
	int				d;
	int				s;
}					t_q;

/**
 * @brief struct for command bilder
 */
typedef struct s_cb
{
	t_cmd			*cmds;
	t_cmd			*c_cmd;
	int				i;
	t_list			*token;
}					t_cb;

#endif
