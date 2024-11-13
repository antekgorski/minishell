# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agorski <agorski@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 14:45:11 by agorski           #+#    #+#              #
#    Updated: 2024/11/13 15:45:11 by agorski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# to compile the minishell
#cc minishell.c -lreadline -o minishell

# to check for memory leaks without readline
# valgrind --leak-check=full --suppressions=../writing_helpers/valgrind_ignore.md ./minishell