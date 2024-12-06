# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agorski <agorski@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 17:51:39 by fcorvaro          #+#    #+#              #
#    Updated: 2024/12/06 16:33:49 by agorski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- Output: Appereance ------------------------------------------------------ #
# Start and end sequences for color codes -- REMEMBER (add ; and m)
START = \033[
END = \033[0m
# ------------  FOREGROUND COLORS  ------------------------------------------- #
# Black, Red, Green, Yellow, Blue, Magenta, Cyan, White #
BK = 30
R = 31
G = 32
Y = 33
BE = 34
M = 35
C = 36
W = 37
# ------------  BACKGROUND COLORS  ------------------------------------------- #
# Black, Red, Green, Yellow, Blue, Magenta, Cyan, White #
BKK = 40
RR = 41
GG = 42
YY = 43
BEE = 44
MM = 45
CC = 46
WW = 47
# ------------  TEXT STYLES  ------------------------------------------------- #
# Bold text, Faint text, Italic text, Underlined text, Blinking text ...#
#... Reverse colors, Hidden text, Strikethrough text #
BOLD = 1
FAINT = 2
ITALIC = 3
UNDERLINE = 4
BLINKING = 5
REVERSE =7
HIDDEN = 8
STRIKE = 9

# ------------  COMPILER COMMAND  -------------------------------------------- #
CC = gcc
# ------------  REMOVE COMMAND  ---------------------------------------------- #
RM = rm -rf
# ------------  COMPILER FLAGS  ---------------------------------------------- #
CFLAGS = -Wall -Wextra -Werror -g -pthread
# ------------  BUILD FILE NAME  --------------------------------------------- #
BUILD = minishell
# ------------  FULL PATH TO THE BUILD FILE  --------------------------------- #
NAME = $(BUILD)

# ------------  INCLUDE DIRECTORIES AND LIBRARY FLAGS  ----------------------- #
INCLUDE = -I/usr/include/readline -I./include
READLINE_FLAGS = -lreadline -L/usr/lib

# ------------  LIBFT FILE PATH  --------------------------------------------- #
LIBFT	=	./libft/libft.a

# ------------  SOURCE FILES AND DIRECTORIES  -------------------------------- #
SRCS_DIR = srcs
SRCS = $(shell find $(SRCS_DIR) -name "*.c")

# ------------  OBJECT FILES AND DIRECTORIES  -------------------------------- #
OBJS_DIR = objs
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

# ------------  INCLUDE DEPENDENCY FILES  ------------------------------------ #
-include $(OBJS_DIR)/*.d

# ------------  PHONY TARGETS  ----------------------------------------------- #
.PHONY: all clean fclean re help 

# ------------  ALL TARGET  -------------------------------------------------- #
all:
	@make -s $(NAME)

# ------------  LIBFT COMPILATION COMMAND  ----------------------------------- #
$(LIBFT):
	@echo "$(START)$(BOLD);$(ITALIC);$(Y)mStarting compilation of libft...$(END)"
	@make -sC ./libft
	@echo "$(START)$(BOLD);$(ITALIC);$(G)mCompilation of libft completed successfully.$(END)"

# ------------  OBJECT FILES COMPILATION COMMAND  ---------------------------- #	
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	@echo "$(START)$(BOLD);$(ITALIC);$(Y)mCompiling $<$(END)"
	$(CC) $(CFLAGS) $(INCLUDE) $(READLINE_FLAGS) -c $< -o $@

# ------------  EXECUTABLE FILE COMPILATION COMMAND  ------------------------- #
$(NAME): $(LIBFT) $(OBJS)
	@echo "$(START)$(BOLD);$(ITALIC);$(Y)mLinking objects and creating executable...$(END)"
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) $(READLINE_FLAGS) -o $(NAME)
	@echo "$(START)$(BOLD);$(ITALIC);$(G)mCompilation of $(NAME) completed successfully! (Mandatory part only).$(END)"
	@echo "$(START)$(BOLD);$(ITALIC);$(BE)m To run the program, use: ./$(BUILD)$(END)"
	@echo "  - After launching the program, you can run commands in the following format: <command> [arguments]"
	@echo "  - $(START)$(BOLD);$(ITALIC);$(C)m<command>$(END): The command you want to execute."
	@echo "  - $(START)$(BOLD);$(ITALIC);$(C)m[arguments]$(END): The arguments for the command (optional)."
	@echo "$(START)$(BOLD);$(ITALIC);$(M)mAuthors: fursini & fcorvaro$(END)"

# ------------  CLEAN TARGET  ------------------------------------------------ #
clean:
	@make clean -s -C ./libft
	@if [ -d "$(OBJS_DIR)" ]; then \
		$(RM) -r $(OBJS_DIR); \
		echo "$(START)$(BOLD);$(ITALIC);$(G)m Cleaned up object files. $(OBJS_DIR) has been removed. $(END)"; \
	fi

# ------------  FCLEAN TARGET  ----------------------------------------------- #
fclean: clean
	@make fclean -sC ./libft
	@if [ -f "$(NAME)" ]; then \
		$(RM) $(NAME); \
		echo "$(START)$(BOLD);$(ITALIC);$(G)m Cleaned up build. $(NAME) has been removed. $(END)"; \
	fi
	
# ------------  RE TARGET  --------------------------------------------------- #
re:	fclean 
	@$(MAKE) -s all

# ------------  HELP TARGET  ------------------------------------------------- #
help:
	@echo "  $(START)$(BOLD);$(ITALIC);$(G)mAvailable targets:$(END)"
	@echo "  make [command]"
	@echo ""
	@echo "  $(START)$(BOLD);$(Y)mall\t\tCompile the project$(END)"
	@echo "  $(START)$(BOLD);$(Y)mclean\t\tRemove object files$(END)"
	@echo "  $(START)$(BOLD);$(Y)mfclean\tRemove object files and the executable$(END)"
	@echo "  $(START)$(BOLD);$(Y)mre\t\tRecompile the project$(END)"
	@echo "  $(START)$(BOLD);$(Y)mhelp\t\tDisplay this help message$(END)"
	@echo ""
	@echo "  $(START)$(BOLD);$(M)mProject Description:$(END)"
	@echo "  This project, known as 'Minishell', is a simple shell implementation"
	@echo "  in C. The program simulates a basic command-line interpreter, where"
	@echo "  each command is read, parsed, and executed in a loop until an exit"
	@echo "  command is received. The shell supports a subset of standard commands"
	@echo "  and features, including variable expansion and command chaining."
	@echo "  The project demonstrates understanding of process creation and"
	@echo "  synchronization, signal handling, and terminal I/O."
