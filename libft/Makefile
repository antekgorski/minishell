# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 16:10:34 by agorski           #+#    #+#              #
#    Updated: 2024/12/23 16:41:58 by agorski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re test bonus
CC= cc
CFLAGS= -Wextra -Werror -Wall -fPIC
TESTFLAGS= -fsanitize=address -g			
NAME= libft.a
O_DIR= obj
# OBJ= $(patsubst %.c,%.o,$(SRC))
OBJ= $(SRC:%.c=$(O_DIR)/%.o)
B_OBJ= $(SRC_BONUS:%.c=$(O_DIR)/%.o)
# SRC= $(wildcard *.c)
SRC= ft_isalnum.c ft_isascii.c ft_isprint.c ft_memmove.c ft_strlcat.c ft_strlen.c \
ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memcpy.c ft_memset.c ft_strlcpy.c  ft_toupper.c \
ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strcmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_printf.c print_char.c print_string.c print_hex.c print_number.c \
print_unsigned.c print_pointer.c get_next_line_bonus.c get_next_line.c get_next_line_utils_bonus.c \
get_next_line_utils.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c \

all: $(NAME)

$(O_DIR):
	mkdir -p $(O_DIR)

$(NAME): $(O_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)		# archive *.o file to NAME.a \n

$(O_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@		# *.o files create from *.c \n

clean:
	rm -f $(O_DIR)/*.o	    # remove .o files
	rm -rf $(O_DIR)			# remove obj directory

fclean: clean
	rm -f $(NAME)    # remove .o files and libft.a

re: fclean all		# remove .o files and libft.a after compile agen

test:
	nm $(NAME)			# showing what is archive in libft.a

retest: CFLAGS=$(TEST_CFLAGS)
retest: fclean all	# compile with test flags
