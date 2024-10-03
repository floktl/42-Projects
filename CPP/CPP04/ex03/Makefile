# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 07:02:13 by fkeitel           #+#    #+#              #
#    Updated: 2024/10/02 12:21:48 by fkeitel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Interface

SRC = AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp main.cpp

CFLAGS = -Wall -Wextra -Werror -std=c++17 -g

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
