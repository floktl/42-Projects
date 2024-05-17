# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 10:25:10 by fkeitel           #+#    #+#              #
#    Updated: 2024/04/30 10:22:00 by fkeitel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME    := minishell

# Flags
CFLAGS  := -Wall -Werror -Wextra -g
LDLIBS  := -lreadline

# Directories
SRC_DIR := src
OBJ_DIR := obj

# Source files, Libraries targets
SRCS    := $(shell find $(SRC_DIR) -name '*.c')
LIBFT   := libft/
LIBFTTARGET := libft/libft.a
OBJS    := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Header file
HEADER  := minishell.h

# Rule to build the project
all: $(OBJ_DIR) $(NAME) $(HEADER)
	@echo "$(NAME) successfully built!"

# Rule to build the project using MLX library
$(NAME): $(OBJS) $(LIBFTTARGET)
	@$(CC) $(CFLAGS)  $(OBJS) -o $@ $(LIBFTTARGET) $(LDLIBS)

$(LIBFTTARGET):
	@$(MAKE) -C $(LIBFT)

# Rule to compile source files into object files in a separate obj folder
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(HEADER)
	@mkdir -p $(dir $@)
	@$(info Compiling $<)
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
