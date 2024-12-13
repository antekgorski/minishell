CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

LIBFT_DIR = ./libft
LIBPRINTF_DIR = ./ftprintf

NAME = libdmoroz.a
GNL_DIR = ./ftgnl
SRCS_GNL = get_next_line.c get_next_line_utils.c
SRCS = $(addprefix $(GNL_DIR)/, $(SRCS_GNL))
OBJS = $(SRCS:.c=.o)
INCS = $(LIBFT_DIR)/libft.h \
       $(GNL_DIR)/get_next_line.h
INCS_DIR = $(dir $(INCS))
INC_FLAGS = $(addprefix -I, $(INCS_DIR))

all: $(NAME)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) $(INC_FLAGS) $(LIB_FLAGS) $< -o $@ 

$(NAME): libprintf $(OBJS)
	cp $(LIBPRINTF_DIR)/libftprintf.a $(NAME)
	ar r $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C $(LIBPRINTF_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBPRINTF_DIR)
	rm -f $(NAME)

re: fclean all

bonus: all

libprintf:
	$(MAKE) all bonus clean -C $(LIBPRINTF_DIR)

.PHONY: all clean fclean re libft
