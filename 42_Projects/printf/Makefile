# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 10:58:51 by fkeitel           #+#    #+#              #
#    Updated: 2023/11/23 11:05:14 by fkeitel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR = src
LIBFTDIR = libft

SRC = 	src/ft_printf.c src/ft_checkcases.c src/ft_printstr.c src/ft_putchar.c src/ft_puthex.c src/ft_putnbrui.c \
			src/ft_putunbr.c \

OBJ = $(SRC:$(SRCDIR)/%.c=$(SRCDIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(SRCDIR) -I $(LIBFTDIR)
LDFLAGS = -L $(LIBFTDIR) -lft

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	cp $(LIBFTDIR)/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ)


$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) all

fclean: clean
	rm -f $(NAME)

re: 		fclean all

.PHONY: all clean fclean re
