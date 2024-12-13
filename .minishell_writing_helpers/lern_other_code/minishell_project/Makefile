# Compiler and flags
CC = clang
CFLAGS = -Wall -Wextra -Werror
C_PRECOMPILE_FLAGS = -c
C_DEBUG_FLAG = -g

# Directories and files
LIBFT_DIR = ./libft
LIBFT_NAME = libdmoroz.a
LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

INC_DIR = ./include
SRC_DIR = ./src

# Source files
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/builtin/cmd_cd.c \
       $(SRC_DIR)/builtin/cmd_echo.c \
       $(SRC_DIR)/builtin/cmd_env.c \
       $(SRC_DIR)/builtin/cmd_exit.c \
       $(SRC_DIR)/builtin/cmd_export.c \
       $(SRC_DIR)/builtin/cmd_pwd.c \
       $(SRC_DIR)/builtin/cmd_unset.c \
       $(SRC_DIR)/env/env_create.c \
       $(SRC_DIR)/env/env_init.c \
       $(SRC_DIR)/env/env_modify.c \
       $(SRC_DIR)/env/env_utils.c \
       $(SRC_DIR)/exec/execute.c \
       $(SRC_DIR)/exec/execute_builtin.c \
       $(SRC_DIR)/exec/execute_cmd.c \
       $(SRC_DIR)/exec/execute_proc.c \
       $(SRC_DIR)/exec/execute_utils.c \
       $(SRC_DIR)/parser/create_default_pipeline_node.c \
       $(SRC_DIR)/parser/parser.c \
       $(SRC_DIR)/parser/parser_utils.c \
       $(SRC_DIR)/parser/replace_vars.c \
       $(SRC_DIR)/parser/replace_wildcards.c \
       $(SRC_DIR)/parser/set_redirections.c \
       $(SRC_DIR)/parser/split_line.c \
       $(SRC_DIR)/parser/split_tokens_per_command.c \
       $(SRC_DIR)/pipe/pipe.c \
       $(SRC_DIR)/signal/signal.c \
       $(SRC_DIR)/utils/free_pipeline.c \
       $(SRC_DIR)/utils/free_shell.c \
       $(SRC_DIR)/utils/free_split.c \
       $(SRC_DIR)/utils/ft_atol.c \
       $(SRC_DIR)/utils/ft_isspace.c \
       $(SRC_DIR)/utils/get_split_size.c \
       $(SRC_DIR)/utils/validate_pipeline.c

# Object files
OBJS = $(SRCS:.c=.o)

# Include files
INCS = $(INC_DIR)/environment.h \
       $(INC_DIR)/execute.h \
       $(INC_DIR)/messages.h \
       $(INC_DIR)/minishell.h \
       $(INC_DIR)/parser.h \
       $(INC_DIR)/signals.h \
       $(LIBFT_DIR)/libft/libft.h \
       $(LIBFT_DIR)/ftprintf/ft_printf.h \
       $(LIBFT_DIR)/ftgnl/get_next_line.h
INCS_DIR = $(dir $(INCS))
INC_FLAGS = $(addprefix -I, $(INCS_DIR))

# Library flags
LIB_FLAGS = -lreadline -L$(LIBFT_DIR)/ -ldmoroz 

# Output binary name
NAME = minishell

# Rules
all: $(NAME)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) $(C_PRECOMPILE_FLAGS) $(INC_FLAGS) $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS) $(LIB_FLAGS) -o $(NAME)

debug: $(LIBFT)
	$(CC) $(C_DEBUG_FLAG) $(INC_FLAGS) $(SRCS) $(LIB_FLAGS) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

bonus: all

$(LIBFT):
	$(MAKE) all -C $(LIBFT_DIR)

.PHONY: all clean fclean re bonus
