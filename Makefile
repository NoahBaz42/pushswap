NAME = push_swap

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -I.
CDEPS =  -MMD -MP

INCLUDES = -I.

LIBFT_DIR = libft_pushswap
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
BONUS = bonus

LIBS = -L$(LIBFT_DIR) -lft
LIBS += -L$(PRINTF_DIR) -lftprintf

# CONSIDER:
#	- go over naming conventions
# 	- restructure directories
#	- revisit makefile rules
#	  (recommended: see https://codeberg.org/maloryware/pushswap/src/branch/main/Makefile)

MIN = 0
MAX = 999
COUNT = 20
DEFAULT_ARGS = $(shell shuf -i $(MIN)-$(MAX) -n $(COUNT))


ARGS = $(DEFAULT_ARGS)

SRCS = test_main.c \
		operations_push.c \
		operations_rotate.c \
		operations_swap.c \
		operations_rrotate.c \
		stack_is_3.c \
		utils_1.c \
		utils_2.c \
		index.c \
		simple_alg.c \
		stack_is_5.c \
		complex_alg.c \
		medium_alg.c \
		optimization.c \
		pushswap_exit.c \
		stack_a.c \
		parsing.c \
		parsing_split.c \
		parsing_utils.c \
		flag_bench.c \
		flag_check.c \
		flag_diff.c \
		pushswap.c \
		bench.c \
		free_parsing.c

vpath %.c pushswap_algorithms pushswap_op utils flags parsing output

OBJS_DIR = objs/
OBJ = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_DIR),$(OBJ))

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJS_DIR)%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CDEPS) -c $(INCLUDES) $< -o $@

-include $(OBJS:.o=.d)

$(OBJS_DIR):
	mkdir $@

run: $(NAME)
	./$(NAME) $(ARGS)

check: $(NAME)
	$(eval ARG := $(ARGS))
	./$(NAME) $(ARG) | ./checker_linux $(ARG)

gdb: $(NAME)
	@gdb --tui --args ./$(NAME) $(ARGS)

valgrind vg: $(NAME)
	valgrind ./$(NAME) $(ARGS)

valgrindplus vgp: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --keep-stacktraces=alloc-and-free ./$(NAME) $(ARGS)

bonus: $(NAME)
	make -C $(BONUS)


clean:
	rm -rf $(OBJS_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	make -C $(BONUS) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	make -C $(BONUS) fclean

re: fclean all

.PHONY: all clean fclean re run gdb bonus
