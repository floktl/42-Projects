# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stopp <stopp@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 10:25:10 by fkeitel           #+#    #+#              #
#    Updated: 2024/06/10 17:35:51 by stopp            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME    := minishell

# Define ANSI color codes
GREEN := \033[0;32m
NC := \033[0m

# Flags
CFLAGS  := -Wall -Werror -Wextra -g
LDLIBS  := -lreadline

# Directories
SRC_DIR := src
OBJ_DIR := obj

# Source files, Libraries targets
SRCS    := src/builtins/builtin_handler.c  src/builtins/cd.c  src/builtins/echo.c \
		src/builtins/env.c  src/builtins/export.c src/builtins/pwd.c \
		src/builtins/unset.c src/clean_functions/clean.c \
		src/error_functions/error.c src/execution_functions/execution.c \
		src/execution_functions/get_path_functions.c src/helper_functions/helper_1.c \
		src/parser_functions/expander.c src/parser_functions/parse_redirects.c \
		src/parser_functions/parsing.c src/parser_functions/process_arg_str.c \
		src/parser_functions/quote_check.c src/parser_functions/redirec_helper.c \
		src/parser_functions/split_pipes.c src/redirect_functions/heredoc.c \
		src/redirect_functions/infile.c src/redirect_functions/outfile_append.c \
		src/redirect_functions/outfile_trunc.c src/signal_functions/signal.c \
		src/utils/lst_utils.c src/utils/debugging.c src/main.c\
		src/utils/util.c\

LIBFT   := libft/
LIBFTTARGET := libft/libft.a
OBJS    := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Header file
HEADER  := minishell.h

MESSAGE := "\n$(GREEN)$(NAME) successfully built!$(NC)\n"

# Rule to build the project
all: $(OBJ_DIR) $(NAME) $(HEADER)
	@echo $(MESSAGE)

# Rule to build the project using MLX library
$(NAME): $(OBJS) $(LIBFTTARGET)
	@$(CC) $(CFLAGS)  $(OBJS) -o $@ $(LIBFTTARGET) $(LDLIBS)

$(LIBFTTARGET):
	@$(MAKE) -C $(LIBFT)

# Rule to compile source files into object files in a separate obj folder
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(HEADER)
	@mkdir -p $(dir $@)
	@echo Compiling:  $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Create the objects directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Rule to clean object files
clean:
	@$(MAKE) -C $(LIBFT) fclean
	@rm -rf $(OBJ_DIR)

# Rule to clean project and object files
fclean: clean
	@rm -rf $(NAME)

# Rule to clean and rebuild the project
re: fclean all

# Phony targets
.PHONY: all clean fclean re Makefile
