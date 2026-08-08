<<<<<<< HEAD
NAME = push_swap

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -I.
CDEPS =  -MMD -MP

LIBFT_DIR = libft_pushswap
LIBFT = $(LIBFT_DIR)/libft.a

# CONSIDER:
#	- go over naming conventions
# 	- restructure directories
#	- revisit makefile rules
#	  (recommended: see https://codeberg.org/maloryware/push_swap/src/branch/main/Makefile)

MIN = 0
MAX = 999
COUNT = 20
DEFAULT_ARGS = $(shell shuf -i $(MIN)-$(MAX) -n $(COUNT))


ARGS = $(DEFAULT_ARGS)

SRCS = test_main.c \
		operations_1.c \
		operations_2.c \
		tiny_sort.c \
		utils_1.c \
		utils_2.c \
		index.c \
		simple_alg.c \
		stack_5.c \
		complex_alg.c \
		medium_alg.c \
		optimization.c \

vpath %.c push_swap_algorithms push_swap_op utils

OBJS_DIR = objs/
OBJ = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_DIR),$(OBJ))

INCLUDES = -I.

all: $(NAME)
=======
NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I. -I$(LIBFT_DIR)

SRCS = parsing.c \
       push_swap_utils.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
>>>>>>> noah_parsing

$(LIBFT):
	make -C $(LIBFT_DIR)

<<<<<<< HEAD
$(NAME): $(OBJS) $(LIBFT) | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CDEPS) -c $(INCLUDES) $< -o $@

-include $(OBJS:.o=.d)

$(OBJS_DIR):
	mkdir $@

run: $(NAME)
	./$(NAME) $(ARGS)

gdb: $(NAME)
	@gdb --tui --args ./$(NAME) $(ARGS)

clean:
	rm -rf $(OBJS_DIR)
=======
all: $(NAME)

clean:
	rm -f $(OBJS)
>>>>>>> noah_parsing
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

<<<<<<< HEAD
.PHONY: all clean fclean re run gdb
=======
.PHONY: all clean fclean re
>>>>>>> noah_parsing
