# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 12:01:53 by fkeitel           #+#    #+#              #
#    Updated: 2024/04/01 12:55:04 by fkeitel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME    := philo

# Compiler and flags
CC      := gcc
CFLAGS  := -Wall -Werror -Wextra -g -pthread

# Directories
SRC_DIR := src
OBJ_DIR := obj

# Source files
SRCS    :=  $(shell find $(SRC_DIR) -name '*.c')
OBJS    := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Header file
HEADER  := philo.h

# Rule to build the project
all: $(OBJ_DIR) $(NAME)
	@echo "$(NAME) successfully built!"

# Rule to build the project
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@

# Rule to compile source files into object files in a separate obj folder
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(HEADER)
	@mkdir -p $(dir $@)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# Create the objects directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Rule to clean object files
clean:
	@rm -rf $(OBJ_DIR)

# Rule to clean project and object files
fclean: clean
	@rm -rf $(NAME)

# Rule to clean and rebuild the project
re: fclean all

# Phony targets
.PHONY: all clean fclean re Makefile

