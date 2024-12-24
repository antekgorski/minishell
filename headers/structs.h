/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:57:01 by agorski           #+#    #+#             */
/*   Updated: 2024/12/24 14:01:56 by agorski          ###   ########.fr       */
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
	t_token			*token;
	t_list			*token_list;
	t_list			*m_env;
	int				f_signal;
	char			*l_hdr;

}					t_minishell;

/**
 * @param t_token token
 * @param char **command
 * @param struct s_node *prev
 * @param struct s_node *next
 * @brief struct for linked list duble or single?
 */
typedef struct s_node
{
	t_token			token;
	char			**command;
	struct s_node	*prev;
	struct s_node	*next;

}					t_node;

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

#endif
