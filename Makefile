# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 19:52:44 by kaoliiny          #+#    #+#              #
#    Updated: 2019/01/12 12:30:52 by kaoliiny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re test mfclean mre

NAME		=	libftprintf.a
SRC_D		=	src/
OBJ_D		=	.obj/

LIB			=	libft/
LIB_N		=	libft.a

SRC			=	manage_float manage_di manage_cs manage_conv ft_printf add_ft
SRCS		=	$(addprefix $(SRC_D), $(addsuffix .c, $(SRC)))
OBJ			=	$(addprefix $(OBJ_D), $(SRCS:%.c=%.o))
INCLUDE		=	-I includes/ -I $(LIB)

CC			=	clang
CFLAGS		=	-g #-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_D) $(OBJ)
	make -C $(LIB)
	cp $(LIB)$(LIB_N) $(NAME)
	ar -r $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_D):
	mkdir -p $(OBJ_D)$(SRC_D)

$(OBJ_D)%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	make clean -C $(LIB)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIB)
	rm -f $(NAME)
	rm -rf $(OBJ_D)

re: fclean all

mfclean:
	rm -rf $(OBJ_D)
	rm -f $(NAME)

mre: mfclean all

test: all
	$(CC) -o unittest.out $(INCLUDE) $(NAME) unittest.c
	./unittest.out
