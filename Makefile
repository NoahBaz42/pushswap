NAME = push_swap

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -I.
CDEPS =  -MMD -MP

INCLUDES = -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR)

LIBFT_DIR = ./libft_pushswap
LIBFT_LIB = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ./ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

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

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

all: $(NAME)

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

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

clean:
	rm -rf $(OBJS_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re run gdb
