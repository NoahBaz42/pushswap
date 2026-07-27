NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP

LIBFT_DIR = ./libft_pushswap
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I. -I$(LIBFT_DIR)

SRCS = test_main.c operations_1.c operations_2.c tiny_sort.c utils.c

vpath %.c push_swap_algorithms push_swap_op

OBJ = $(SRCS:.c=.o)
OBJS_DIR = objs/
OBJS = $(addprefix($(OBJS_DIR),$(OBJ)))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(OBJS_DIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJS_DIR)%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

-include $(OBJECTS:.o=.d)

$(OBJS_DIR):
	mkdir $@

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re