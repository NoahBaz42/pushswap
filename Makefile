NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft_pushswap
LIBFT_LIB = $(LIBFT_DIR)/libft.a
#ADDED PRINTF TO MAKEFILE, TEST REQUIRED
PRINTF_DIR = ./ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

INCLUDES = -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR)

SRCS = flag_bench.c \
	flag_diff.c \
	flag_check.c \
	push_swap_utils.c \
	parsing_utils.c \
	parsing_split.c \
	parsing.c \
	stack_a.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT_LIB) $(PRINTF_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o $(NAME)

.PHONY: $(LIBFT_LIB) $(PRINTF_LIB)

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