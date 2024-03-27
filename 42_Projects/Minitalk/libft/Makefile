# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flo <flo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 09:46:50 by fkeitel           #+#    #+#              #
#    Updated: 2024/03/27 14:59:52 by flo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FT_PRINTFDIR = libft/ft_printf
GET_NEXT_LINEDIR = libft/get_next_line
LIB_DIR = lib
OBJ_DIR := obj

# Define source files in the directory
FT_PRINTF = 	$(FT_PRINTFDIR)/ft_printf.c $(FT_PRINTFDIR)/check_datatypes.c \
			$(FT_PRINTFDIR)/printing_functions.c $(FT_PRINTFDIR)/handle_datatypes.c \

GET_NEXT_LINE = $(GET_NEXT_LINEDIR)/get_next_line_utils.c \
			$(GET_NEXT_LINEDIR)/get_next_line.c \

LIB = $(shell find $(LIB_DIR) -name '*.c')

OBJECTS	=	$(LIB:$(LIB_DIR)/%.c=$(OBJ_DIR)/%.o) \
			$(FT_PRINTF:$(FT_PRINTFDIR)/%.c=$(OBJ_DIR)/%.o) \
			$(GET_NEXT_LINE:$(GET_NEXT_LINEDIR)/%.c=$(OBJ_DIR)/%.o) \

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

# Rule to compile source files from FT_PRINTFDIR into object files
$(OBJ_DIR)/$(FT_PRINTFDIR)/%.o: $(FT_PRINTFDIR)/%.c | $(OBJ_DIR) $(HEADER)
	@mkdir -p $(dir $@)
	@$(info Compiling $<)
	@$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile source files from GET_NEXT_LINEDIR into object files
$(OBJ_DIR)/$(GET_NEXT_LINEDIR)/%.o: $(GET_NEXT_LINEDIR)/%.c | $(OBJ_DIR) $(HEADER)
	@mkdir -p $(dir $@)
	@$(info Compiling $<)
	@$(CC) $(CFLAGS) -c $< -o $@

# Create the objects directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJECTS) all
	@rm -rf $(OBJ_DIR)

fclean:	clean
		$(RM) $(NAME)
		$(RM) libft.a

re:		fclean all

.PHONY:	all clean fclean re Makefile
