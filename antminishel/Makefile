# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agorski <agorski@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 14:45:11 by agorski           #+#    #+#              #
#    Updated: 2024/12/15 18:52:53 by agorski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# to compile the minishell
#cc minishell.c -lreadline -o minishell
#cc /source/minishell.c /source/parser.c -I../libft -L../libft -lft -lreadline -o minishell

# to check for memory leaks without readline
# cc -g minishell.c -lreadline -o minishell
# valgrind --leak-check=full --suppressions=../writing_helpers/valgrind_ignore.md ./minishell

NAME = minishell
SRCS_DIR = source
SRCS = $(shell find $(SRCS_DIR) -name "*.c")

OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = gcc

CFLAGS = -Wall -Wextra -Werror
TEST_CFLAGS = -Wall -Wextra -Werror -lreadline -g -pthread
INCLUDE = -I./headers
REDLINE = -lreadline

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): 
	make all -C libft
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIBFT) $(INCLUDE) $(REDLINE)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

clean:
	rm -f $(OBJS)
	make clean -C libft

re: fclean all

.PHONY: all clean fclean re test