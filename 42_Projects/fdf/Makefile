# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 14:13:59 by fkeitel           #+#    #+#              #
#    Updated: 2024/02/24 16:01:27 by fkeitel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fdf
CFLAGS	:= -Wunreachable-code -Ofast -Wall -Werror -Wextra -g
MLX_FLAGS := -L./MLX42/build -lmlx42 -I../MLX42/include -lglfw -framework Cocoa -framework OpenGL -framework IOKit

SRCS	:= $(shell find src -name '*.c')

LIBFT	:= libft/
LIBFTTARGET := $(LIBFT)/libft.a

OBJS	:= $(SRCS:.c=.o)

all: $(NAME)

mlx:
	@if [ ! -d "MLX42" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git MLX42; \
	else \
		echo "Directory MLX42 already exists."; \
	fi
	@cd MLX42 && cmake -B build && cmake --build build -j4

$(NAME): mlx $(OBJS)
	@$(MAKE) -C $(LIBFT)
	@$(CC) $(OBJS) $(MLX_FLAGS) -o $@ $(LIBFTTARGET)

clean:
	@$(MAKE) -C $(LIBFT) fclean
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx
