# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 10:58:51 by fkeitel           #+#    #+#              #
#    Updated: 2023/12/20 12:40:55 by fkeitel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define directories
SRCDIR = src
LIBFTDIR = libft

# Define source files in the directory
SRC = 	$(SRCDIR)/ft_printf.c $(SRCDIR)/check_datatypes.c \
			$(SRCDIR)/printing_functions.c $(SRCDIR)/handle_datatypes.c \


# Object files, derived from source files
OBJ = $(SRC:$(SRCDIR)/%.c=$(SRCDIR)/%.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(SRCDIR) -I $(LIBFTDIR)
LDFLAGS = -L $(LIBFTDIR) -lft

# Target name
NAME = libftprintf.a

# Default target
all: $(NAME)

# Rule to create the final executable
$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	cp $(LIBFTDIR)/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ)

# Rules for compiling source files into object files
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the build directory
clean:
	rm -f $(OBJ) all
	$(MAKE) -C $(LIBFTDIR) clean

# Full clean (remove all generated files)
fclean: clean
	rm -f $(NAME)

# Rebuild the project from scratch
re: 		fclean all

# Mark targets as not generating any files
.PHONY: all clean fclean re
