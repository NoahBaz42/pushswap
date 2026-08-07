NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft_pushswap
LIBFT_LIB = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ./ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

INCLUDES = -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR)

SRCS = flags/flag_bench.c \
	flags/flag_diff.c \
	flags/flag_check.c \
	parsing/parsing_utils.c \
	parsing/parsing_split.c \
	parsing/parsing.c \
	output/bench.c \
	push_swap_exit.c \
	push_swap_utils.c \
	push_swap.c \
	stack_a.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT_LIB) $(PRINTF_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re