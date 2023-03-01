# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: izaitcev <izaitcev@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/30 14:54:38 by izaitcev      #+#    #+#                  #
#    Updated: 2022/12/07 19:16:21 by izaitcev      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \

SRC_BONUS = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \

OBJ = $(SRC:%.c=%.o)
BONUS_OBJ = $(SRC_BONUS:%.c=%.o)

ifdef ADD_BONUS
COMPILE_OBJS = $(OBJ) $(BONUS_OBJ)
else 
COMPILE_OBJS = $(OBJ)
endif

all: $(NAME) gnl printf

# gnl:
# 	$(MAKE) -C ./get_next_line

printf:
	$(MAKE) -C ./ft_printf

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

.PHONY: all bonus clean fclean re gnl printf