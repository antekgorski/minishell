/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:24:38 by mjakowic          #+#    #+#             */
/*   Updated: 2024/08/02 14:24:40 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXING_H
# define LEXING_H

# include "minishell.h"
# include <stdbool.h>

# define PROMPT "MDshell > "

typedef enum e_token_type
{
	T_TEXT,
	T_LESS,
	T_GREAT,
	T_DLESS,
	T_DGREAT,
	T_PIPE,
	T_NONE,
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	struct s_token	*next;
}					t_token;

void				ft_skip_spaces(char **line);
int					ft_create_add_separator(t_token_type type, char **line,
						t_token **tokens);
t_token				*ft_new_token(char *str, t_token_type type);
void				ft_token_add_back(t_token **tokens, t_token *token);
int					ft_is_separator(char *line);
bool				ft_skip_quotes(char *line, size_t *i);
int					ft_is_quote(char c);
void				ft_list_clear(t_token **tokens);

#endif
