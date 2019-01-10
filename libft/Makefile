# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/27 19:37:45 by kaoliiny          #+#    #+#              #
#    Updated: 2018/11/17 17:49:32 by kaoliiny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
SRCS :=	ft_strcmp \
	ft_toupper \
	ft_strcpy \
	ft_strdup \
	ft_atoi \
	ft_strlen \
	ft_isalnum \
	ft_strncat \
	ft_isalpha \
	ft_strncmp \
	ft_isascii \
	ft_strncpy \
	ft_isdigit \
	ft_strnstr \
	ft_isprint \
	ft_strrchr \
	ft_strcat \
	ft_strstr \
	ft_strchr \
	ft_tolower \
	ft_memmove \
	ft_memcpy \
	ft_memccpy \
	ft_memcmp \
	ft_memset \
	ft_bzero \
	ft_memchr \
	ft_strlcat \
	ft_putstr_fd \
	ft_putchar_fd \
	ft_putendl_fd \
	ft_putendl \
	ft_putnbr_fd \
	ft_putnbr \
	ft_putstr \
	ft_putchar \
	ft_memalloc \
	ft_memdel \
	ft_strnew \
	ft_strdel \
	ft_strclr \
	ft_striter \
	ft_striteri \
	ft_strmap \
	ft_strmapi \
	ft_strequ \
	ft_strnequ \
	ft_strsub \
	ft_strsplit \
	ft_strjoin \
	ft_lstnew \
	ft_lstdelone \
	ft_randint \
	ft_lstadd \
	ft_lstiter \
	ft_strtrim \
	ft_lstdel \
	ft_itoa \
	ft_lstmap \
	get_next_line

SRC := $(addsuffix .c, $(SRCS))
INC := includes
CFLAGS := -Wall -Wextra -Werror
LIBS := $(SRC:%.c=%.o)


all: $(NAME)

$(NAME):
	gcc -c $(SRC) -I $(INC) $(CFLAGS)
	ar rc libft.a $(LIBS)
	ranlib libft.a

clean:
	/bin/rm -f $(LIBS)
fclean: clean
	/bin/rm -f libft.a
re: fclean all
