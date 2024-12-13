CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS_FTSTR = ft_substr.c \
             ft_striteri.c \
             ft_strmapi.c \
             ft_strchr.c \
             ft_strrchr.c \
             ft_split.c \
             ft_strtrim.c \
             ft_strjoin.c \
             ft_strlcat.c \
             ft_strdup.c \
             ft_strcmp.c \
             ft_strncmp.c \
             ft_strnstr.c \
             ft_strlcpy.c \
             ft_strlen.c

SRCS_FTCHAR = ft_isdigit.c \
              ft_isalpha.c \
              ft_isprint.c \
              ft_toupper.c \
              ft_isalnum.c \
              ft_tolower.c \
              ft_isascii.c

SRCS_FTWRITE = ft_putnbr_fd.c \
               ft_putendl_fd.c \
               ft_putchar_fd.c \
               ft_putstr_fd.c

SRCS_FTMEM = ft_memmove.c \
             ft_memchr.c \
             ft_memset.c \
             ft_memcmp.c \
             ft_memcpy.c \
             ft_bzero.c

SRCS_FTLIST = ft_lstiter_bonus.c \
              ft_lstdelone_bonus.c \
              ft_lstsize_bonus.c \
              ft_lstadd_back_bonus.c \
              ft_lstnew_bonus.c \
              ft_lstmap_bonus.c \
              ft_lstadd_front_bonus.c \
              ft_lstclear_bonus.c \
              ft_lstlast_bonus.c

SRCS_OTHERS = ft_atoi.c \
              ft_itoa.c \
              ft_calloc.c

SRCS = $(addprefix ftstr/, $(SRCS_FTSTR)) \
      $(addprefix ftchar/, $(SRCS_FTCHAR)) \
      $(addprefix ftwrite/, $(SRCS_FTWRITE)) \
      $(addprefix ftmem/, $(SRCS_FTMEM)) \
      $(SRCS_OTHERS)

BONUS_SRCS = $(addprefix ftlist/, $(SRCS_FTLIST))
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
INCS = libft.h
INCS_DIR = ./

all: $(NAME)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS_DIR)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS_OBJS)
	ar r $(NAME) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus
