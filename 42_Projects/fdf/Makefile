# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 14:13:59 by fkeitel           #+#    #+#              #
#    Updated: 2024/03/12 09:17:35 by fkeitel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##
##		MAkefile for compiling all c files into the exetutable "fdf"
##

# Project name
NAME	:= fdf
# flags
CFLAGS	:= -Wunreachable-code -Ofast -Wall -Werror -Wextra -g 
MLX_FLAGS := -L./MLX42/build -lmlx42 -I../MLX42/include -lglfw -framework Cocoa -framework OpenGL -framework IOKit

# Source files, Libraries targets
SRCS	:= $(shell find src -name '*.c')
LIBFT	:= libft/
LIBFTTARGET := $(LIBFT)/libft.a
OBJS	:= $(SRCS:.c=.o)

# Rule to build the project
all: $(NAME)
	@echo "$(NAME) successfully built!"

# Rule to fetch and build MLX library
mlx:
	@if [ ! -d "MLX42" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git MLX42; \
		cd MLX42 && cmake -B build && cmake --build build -j4; \
	else \
		echo "Directory MLX42 already exists."; \
	fi

# Rule to build the project using MLX library
$(NAME): mlx $(OBJS) $(LIBFTTARGET)
	@$(CC) $(OBJS) $(MLX_FLAGS) -o $@ $(LIBFTTARGET)

$(LIBFTTARGET):
	@$(MAKE) -C $(LIBFT)

# Rule to clean object files
clean:
	@$(MAKE) -C $(LIBFT) fclean
	@rm -rf $(OBJS)

# Rule to clean project and object files
fclean: clean
	@rm -rf $(NAME)

# Rule to clean and rebuild the project
re: fclean all

# Phony targets
.PHONY: all clean fclean re mlx
