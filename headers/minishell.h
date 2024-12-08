/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:36:02 by agorski           #+#    #+#             */
/*   Updated: 2024/12/06 20:38:08 by agorski          ###   ########.fr       */
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

//parser functions
char	**parse(void *line);

#endif


// typedef struct s_list
// {
// 	int				token;
// 	char			*command;
//     struct s_list	*prev;
// 	struct s_list	*next;
    
// }					t_list;

// t_list				*parse(void *line, t_list *command_list);