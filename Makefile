NAME = push_swap

SRCS = operations_1.c \
		operations_2.c \

OBJS = $(SRCS:.c=.o)

SOURCES = $(SRCS)
OBJECTS = $(OBJS)
CC = clang
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./libft_pushswap
INCLUDES =-I. -I$(LIBFT_DIR)
LIBFT = $(LIBFT_DIR)/libft.a

all:  $(NAME) $(LIBFT)

$(LIBFT):
	cd $(LIBFT_DIR) && make

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

diff:
	$(info the status of the repository and the volume of per-file changes:)
	@git status
	@git diff --stat

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re diff