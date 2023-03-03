# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: izaitcev <izaitcev@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/05/16 16:28:41 by izaitcev      #+#    #+#                  #
#    Updated: 2022/06/28 16:22:21 by izaitcev      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
	ft_printf_utils.c\
	ft_printf_nbr.c\
	ft_print_hex.c\

SRC_BONUS = 

OBJ = $(SRC:%.c=%.o)
BONUS_OBJ = $(SRC_BONUS:%.c=%.o)

ifdef ADD_BONUS
COMPILE_OBJS = $(OBJ) $(BONUS_OBJ)
else 
COMPILE_OBJS = $(OBJ)
endif

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(COMPILE_OBJS)
	ar rc $(NAME) $(COMPILE_OBJS)

bonus:
	@ $(MAKE) ADD_BONUS=1 all

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re