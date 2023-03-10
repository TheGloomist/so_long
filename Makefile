NAME 	:= so_long
CC		:= gcc
CFLAGS 	:= -Wall -Wextra -Werror -Imlx -g -fsanitize=address
LIBMLX 	:= ./MLX42
LIBFT	:= ./LIBFT_folder

HEADERS := -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include
LIBS	:= $(LIBMLX)/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

ifeq ($(shell uname -s), Darwin)
	GLFW := $(shell brew --prefix glfw)/lib
	LIBS += -L $(GLFW)
else
	LIBS += -ldl
endif

all: libmlx libft $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

libft:
	@$(MAKE) -C $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean
	@$(MAKE) -C $(LIBFT) clean


fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIBFT) fclean

re: clean all

.PHONY: all, libmlx, libft, clean, fclean, re