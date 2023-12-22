# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 10:58:51 by fkeitel           #+#    #+#              #
#    Updated: 2023/12/07 09:53:47 by fkeitel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define directories
SORTDIR = sorting_functions
CREATEDIR = create
LIBFTDIR = libft
ERRORDIR = error_handling
SORTINGDIR = sorting_algorithm
HELPERDIR = helper_functions

# Define source files in each directory
SORT = 	push.c swap.c rotate.c reverse_rotate.c \

CREATE = main.c print_stack.c \

ERROR = argument_errors.c find_error_type.c stack_errors.c \

SORTING = algorithm.c algorithm_help_functions.c under_five_nodes_alg.c \

HELPER = help_functions_1.c help_functions_2.c \

# Object files, derived from source files
OBJ = $(SORT:%.c=$(SORTDIR)/%.o) $(CREATE:%.c=$(CREATEDIR)/%.o) \
		$(ERROR:%.c=$(ERRORDIR)/%.o) $(SORTING:%.c=$(SORTINGDIR)/%.o) \
		$(HELPER:%.c=$(HELPERDIR)/%.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(SORTDIR) -I $(CREATEDIR) -I $(LIBFTDIR)\
		-I $(ERRORDIR) -I $(SORTINGDIR) -I $(HELPERDIR)
LDFLAGS = -L $(LIBFTDIR) -lft

# Target executable name
NAME = push_swap

# Default target
all: $(NAME)

# Rule to create the final executable
$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

# Rules for compiling source files into object files
$(SORTDIR)/%.o: $(SORTDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(CREATEDIR)/%.o: $(CREATEDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(ERRORDIR)/%.o: $(ERRORDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(HELPERDIR)/%.o: $(HELPERDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the build directory
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFTDIR) clean

# Full clean (remove all generated files)
fclean: clean
	rm -f $(NAME)

# Rebuild the project from scratch
re: fclean all

# Mark targets as not generating any files
.PHONY: all clean fclean re
