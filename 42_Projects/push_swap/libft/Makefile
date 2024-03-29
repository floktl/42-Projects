# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 09:46:50 by fkeitel           #+#    #+#              #
#    Updated: 2024/03/27 17:08:19 by fkeitel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIB_DIR = lib
OBJ_DIR := obj

# Define source files in the directory

LIB = $(shell find $(LIB_DIR) -name '*.c')

OBJECTS	=	$(LIB:$(LIB_DIR)/%.c=$(OBJ_DIR)/%.o) \

HEADER := libft.h

CC				= cc -g
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

all:	$(OBJ_DIR) $(NAME) $(HEADER)
	@echo "$(NAME) successfully built!"

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

# Rule to compile source files into object files in a seperate obj folder
$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c | $(OBJ_DIR) $(HEADER)
	@mkdir -p $(dir $@)
	@$(info Compiling $<)
	@$(CC) $(CFLAGS) -c $< -o $@

# Create the objects directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJECTS) all
	@rm -rf $(OBJ_DIR)

fclean:	clean
		$(RM) $(NAME)
		$(RM) libft.a

re:		fclean all

.PHONY:	all clean fclean re Makefile
