NAME = minishell
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I inc
LIBFT = libs/libft/libft.a
LIBS = $(LIBFT) $(FT_PRINTF) -lreadline -lm -g
Files =		src/main \
					src/main_signals \
 					src/tokens/tokens \
					src/tokens/token_handl \
					src/tokens/token_util \
					src/tokens/token_list_ft \
					src/parse/parse_nodes \
					src/parse/parse_text \
					src/parse/parse \
					src/parse/parse_utils \
					src/parse/parse_clr \
					src/parse/parse_errors \
					src/builtins/env \
					src/builtins/env_ut \
					src/builtins/cd \
					src/builtins/echo \
					src/builtins/pwd \
					src/builtins/unset \
					src/builtins/exit \
					src/builtins/export \
					src/exec/init_tree \
					src/exec/exec_builtin \
					src/exec/exist_check \
					src/exec/ft_exec_command \
					src/exec/ft_exec_node \
					src/exec/ft_get_path \
					src/exec/exec_redirect \
					src/exec/error_msg \
					src/exec/heredoc \
					src/expander/expand \
					src/expander/expand_utils \
					src/expander/ft_clean_empty \
					src/expander/ft_expander_split \
					src/expander/strip_quotes \
					src/expander/heredoc_expander \
					src/garbage/garbage_colector \

SRCS = $(Files:%=%.c)
OBJS = $(Files:%=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT):
	make -C libs/libft

clean:
	make -C libs/libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libs/libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
