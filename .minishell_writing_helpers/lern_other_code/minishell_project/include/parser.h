/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:26:08 by sehosaf           #+#    #+#             */
/*   Updated: 2024/07/18 17:19:48 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"
# include "libft.h"

char		**split_line(char *line);
void		split_tokens_per_command(t_pipeline *start, char **tokens);
t_pipeline	*create_default_pipeline_node(void);
int			set_redirections(t_pipeline *node);
void		remove_cmd_arg(t_pipeline *node, int ind);
void		replace_vars(t_pipeline *node, t_shell *shell);
void		replace_wildcards(t_pipeline *node);
char		*get_var_name(char *dollar);
char		*get_var_value(const char *name, t_shell *shell);

#endif
