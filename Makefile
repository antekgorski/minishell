# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agorski <agorski@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 14:45:11 by agorski           #+#    #+#              #
#    Updated: 2025/01/21 16:32:25 by agorski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRCS_DIR = source
# we must change this becouse of the norminette!!
SRCS = $(shell find $(SRCS_DIR) -name "*.c")

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