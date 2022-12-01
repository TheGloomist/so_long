NAME 	:= so_long
CFLAGS 	:= -Wall -Wextra -Werror
LIBMLX 	:= ./MLX42

HEADERS := -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

ifeq ($(shell uname -s), Darwin)
	GLFW := $(shell brew --prefix glfw)/lib
	LIBS += -L $(GLFW)
else
	LIBS += -ldl
endif

all: libmlx $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean

re: clean all

.PHONY: all, libmlx, clean, fclean, re