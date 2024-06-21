# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 09:46:50 by fkeitel           #+#    #+#              #
#    Updated: 2024/06/06 13:20:53 by fkeitel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIB_DIR = lib
OBJ_DIR := obj

# Define source files in the directory

LIB = lib/append_int.c lib/bits_to_char.c lib/free_two_dimensional_array.c \
		lib/ft_atoi.c lib/ft_bzero.c lib/ft_calloc.c lib/ft_isalnum.c \
		lib/ft_isalpha.c lib/ft_isascii.c lib/ft_isdigit.c lib/ft_isprint.c \
		lib/ft_itoa.c lib/ft_lstadd_back.c lib/ft_lstadd_front.c lib/ft_lstclear.c \
		lib/ft_lstdelone.c lib/ft_lstiter.c lib/ft_lstlast.c lib/ft_lstnew.c \
		lib/ft_lstsize.c lib/ft_memchr.c lib/ft_memcmp.c lib/ft_memcpy.c \
		lib/ft_memmove.c lib/ft_memset.c lib/ft_putchar_fd.c \
		lib/ft_putendl_fd.c lib/ft_putnbr_fd.c lib/ft_putstr_fd.c lib/ft_realloc.c \
		lib/ft_split.c lib/ft_strchr.c lib/ft_strdup.c lib/ft_striteri.c \
		lib/ft_strjoin.c lib/ft_strlcat.c lib/ft_strlcpy.c lib/ft_strlen.c \
		lib/ft_strmapi.c lib/ft_strncmp.c lib/ft_strnstr.c lib/ft_strrchr.c \
		lib/ft_strtrim.c lib/ft_substr.c lib/ft_tolower.c lib/ft_toupper.c \
		lib/insert_char_at_pos.c lib/is_substr_first_word.c \
		lib/null_term_string.c lib/rem_char.c lib/remove_char.c \
		lib/replace_substr.c lib/strjoin_free.c \
		lib/get_next_line/get_next_line.c lib/ft_printf/check_datatypes.c \
		lib/ft_printf/ft_printf.c lib/ft_printf/handle_datatypes.c \
		lib/ft_printf/printing_functions.c \

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
