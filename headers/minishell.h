/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:36:02 by agorski           #+#    #+#             */
/*   Updated: 2024/12/10 18:27:41 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>

# define PROMPT "antpaw$"

typedef enum e_token
{
    DQUOTE,         // "
	SQUOTE,         // '
	PIPE,           // |
	IREDIR,         // <
	OREDIR,         // >
	APPEND,         // >>
	HERDOC,         // <<
    CMD,            // command
    TO_PARSE       // to parse
}					t_token;

typedef struct s_node
{
	t_token			token;
	char			*command;
	struct s_node	*prev;
	struct s_node	*next;

}					t_node;
// parser functions
char				**parse(void *line);
int	check_quote(char *line);

// error handler
void panic(char *message);


#endif

// t_list				*parse(void *line, t_list *command_list);