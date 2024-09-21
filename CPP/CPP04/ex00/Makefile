# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 13:50:09 by flo               #+#    #+#              #
#    Updated: 2024/09/20 12:41:22 by fkeitel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Animal

SRC = Animal.cpp Dog.cpp Cat.cpp main.cpp

CFLAGS = -Wall -Wextra -Werror -std=c++17

OBJ = $(SRC:.cpp=.o)

CC = c++

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
