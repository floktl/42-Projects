functions	=	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_strlcat.c ft_strncmp.c \
				ft_substr.c ft_atoi.c ft_isalpha.c ft_memcpy.c ft_strchr.c ft_strlcpy.c \
				ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c \
				ft_memmove.c ft_strlen.c ft_strrchr.c ft_toupper.c ft_calloc.c \
				ft_isdigit.c ft_memchr.c ft_memset.c ft_strjoin.c ft_strtrim.c test.c \

objects	=	$(functions:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

name = libft.a

$(name):	$(objects)
			ar -rcs $(name) $(objects)

all:	$(name)

$(NAME): $(OBJS)
	ar -rcs $(name).a $(objects)

clean:
	rm -rf $(objects)

fclean:	clean
	rm -rf $(name)

re:				fclean $(name).a

.PHONY:			all clean fclean re
