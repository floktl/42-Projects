# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 08:41:04 by fkeitel           #+#    #+#              #
#    Updated: 2024/03/29 13:33:05 by fkeitel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define directories
LIBFTDIR = libft

# Compiler and flags
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I$(LIBFTDIR)
LDFLAGS = -L$(LIBFTDIR) -lft

LEAKFLAG := -L/Users/fkeitel/Documents//LeakSanitizer  -llsan

# Define source files
CLIENT_SRC = client.c
SERVER_SRC = server.c

# Define object files
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

# Define target executables
CLIENT_NAME = client
SERVER_NAME = server

# Default target
all: $(CLIENT_NAME) $(SERVER_NAME)

# Rule to create the client executable
$(CLIENT_NAME): $(CLIENT_OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CLIENT_OBJ) $(LDFLAGS) $(LEAKFLAG) -o  $(CLIENT_NAME)

# Rule to create the server executable
$(SERVER_NAME): $(SERVER_OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(SERVER_OBJ) $(LDFLAGS) $(LEAKFLAG) -o $(SERVER_NAME)

# Generic rule for compiling source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the build directory
clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	$(MAKE) -C $(LIBFTDIR) clean

# Full clean (remove all generated files)
fclean: clean
	rm -f $(CLIENT_NAME) $(SERVER_NAME) libft/libft.a

# Rebuild the project from scratch
re: fclean all

# Mark targets as not generating any files
.PHONY: all clean fclean re
