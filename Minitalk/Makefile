# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 08:41:04 by fkeitel           #+#    #+#              #
#    Updated: 2024/03/31 14:53:39 by fkeitel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define directories
LIBFTDIR = libft
OBJ_DIR := obj
SRC_DIR := src

# Compiler and flags
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I$(LIBFTDIR)
LDFLAGS = -L$(LIBFTDIR) -lft

#LEAKFLAG := -L/Users/fkeitel/Documents/LeakSanitizer -llsan

# Define source files
CLIENT_SRC = $(SRC_DIR)/client.c
SERVER_SRC = $(SRC_DIR)/server.c

# Define object files
CLIENT_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(CLIENT_SRC:.c=.o)))
SERVER_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SERVER_SRC:.c=.o)))

# Define target executables
CLIENT_NAME = client
SERVER_NAME = server

# Default target
all: $(CLIENT_NAME) $(SERVER_NAME)

# Rule to create the client executable
$(CLIENT_NAME): $(CLIENT_OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CLIENT_OBJ) $(LDFLAGS) $(LEAKFLAG) -o $(CLIENT_NAME)

# Rule to create the server executable
$(SERVER_NAME): $(SERVER_OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(SERVER_OBJ) $(LDFLAGS) $(LEAKFLAG) -o $(SERVER_NAME)

# Rule to compile source files into object files in a separate obj folder
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(info Compiling $<)
	@$(CC) $(CFLAGS) -c $< -o $@

# Create the objects directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Clean the build directory
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFTDIR) clean

# Full clean (remove all generated files)
fclean: clean
	rm -f $(CLIENT_NAME) $(SERVER_NAME) libft/libft.a

# Rebuild the project from scratch
re: fclean all

# Mark targets as not generating any files
.PHONY: all clean fclean re
