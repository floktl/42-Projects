# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 09:46:50 by fkeitel           #+#    #+#              #
#    Updated: 2023/10/31 10:02:40 by fkeitel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FUNCTIONS	=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c\
				ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c\
				ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c\
				ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_striteri.c\
				ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c\
				ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c\
				ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_split.c\

OBJECTS	=	$(FUNCTIONS:.c=.o)

BONUS		=	ft_lstnew.c ft_lstsize.c ft_lstadd_front.c ft_lstadd_back.c\
				ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\

BONUS_OBJECTS = $(BONUS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJECTS)
		ar -rcs $(NAME) $(OBJECTS)

clean:
		$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean $(NAME)

bonus: $(BONUS_OBJECTS)
		ar -rcs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

.PHONY:			all clean fclean re bonus
