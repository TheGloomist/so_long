# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: izaitcev <izaitcev@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/30 14:54:38 by izaitcev      #+#    #+#                  #
#    Updated: 2023/03/07 18:37:28 by izaitcev      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a
CC 			= gcc 
CFLAGS 		= -Wall -Wextra -Werror -g -fsanitize=address

HEADERS	= -I ./include
SRC 	= $(shell find ./src -iname "*.c")
OBJS = $(SRC:%.c=%.o)

all: $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c -o $@ $< $(HEADERS)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re isprintf