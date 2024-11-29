# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agorski <agorski@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 14:45:11 by agorski           #+#    #+#              #
#    Updated: 2024/11/29 17:04:05 by agorski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# to compile the minishell
#cc minishell.c -lreadline -o minishell
#cc minishell.c parser.c -I../libft -L../libft -lft -lreadline -o minishell

# to check for memory leaks without readline
# cc -g minishell.c -lreadline -o minishell
# valgrind --leak-check=full --suppressions=../writing_helpers/valgrind_ignore.md ./minishell