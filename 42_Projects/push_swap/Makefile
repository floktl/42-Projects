# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flo <flo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 10:58:51 by fkeitel           #+#    #+#              #
#    Updated: 2024/03/25 22:16:43 by flo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME    := push_swap
# Flags
CFLAGS  := -Wunreachable-code -Ofast -Wall -Werror -Wextra -g

# Directories
SRC_DIR := src
OBJ_DIR := obj

# Source files, Libraries targets
SRCS    :=  $(shell find $(SRC_DIR) -name '*.c')
LIBFT   := libft/
LIBFTTARGET := $(LIBFT)/libft.a
OBJS    := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Header file
HEADER  := push_swap.h

# Rule to build the project
all: $(OBJ_DIR) $(NAME) $(HEADER)
	@echo "$(NAME) successfully built!"

# Rule to build the project using MLX library
$(NAME): $(OBJS) $(LIBFTTARGET)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $@ $(LIBFTTARGET)

$(LIBFTTARGET):
	@$(MAKE) -C $(LIBFT)

# Rule to compile source files into object files in a seperate obj folder
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
