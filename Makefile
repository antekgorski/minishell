# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agorski <agorski@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 14:45:11 by agorski           #+#    #+#              #
#    Updated: 2025/01/23 18:36:36 by agorski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRCS_DIR = source
SRCS = source/main.c source/builtins/builtins_utils.c source/builtins/execute.c source/builtins/ft_cd.c \
	source/builtins/ft_echo.c source/builtins/ft_env.c source/builtins/ft_exit.c source/builtins/ft_export.c \
	source/builtins/ft_pwd.c source/builtins/ft_unset.c source/execution/execute_utils1.c source/execution/execute_utils2.c \
	source/execution/execve.c source/parser/case_dolar.c source/parser/cmd_bilder_tool.c source/parser/cmd_bilder.c \
	source/parser/lexter_cmd.c source/parser/lexter_quote.c source/parser/lexter_redir.c source/parser/lexter.c \
	source/parser/parse_quote_loop.c source/parser/parse_quote.c source/parser/parser.c source/parser/rollup_dolar.c \
	source/toolbox/env_list_utils.c source/toolbox/env.c source/toolbox/error_handler.c source/toolbox/free.c \
	source/toolbox/signals.c \

OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread
TEST_CFLAGS = -Wall -Wextra -Werror -g -pthread #-fdiagnostics-color=always #-fsanitize=address	 
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

test_libft:
	$(MAKE) -C $(LIBFT_DIR) CFLAGS="$(TEST_CFLAGS)"

test: test_libft
	$(CC) $(TEST_CFLAGS) $(SRCS) -o $(NAME) $(LIBFT) $(INCLUDE) $(REDLINE)
	
retest:
	make fclean
	make test

.PHONY: all clean fclean re test retest test_libft