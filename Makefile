NAME = push_swap
BONUS = checker

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -I. -Ichecker
CDEPS =  -MMD -MP

LIBFT_DIR = libft_pushswap
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

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
DEFAULT_FLAGS =

ARGS = $(DEFAULT_ARGS)
FLAGS = $(DEFAULT_FLAGS)

SRCS =	operations_push.c \
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
		pushswap_exit.c \
		stack_a.c \
		parsing.c \
		parsing_split.c \
		parsing_utils.c \
		bench_utils.c \
		bench.c \
		flag_check.c \
		flag_diff.c \
		pushswap.c \
		free_parsing.c \
		checker.c \
		checker_utils.c \
		checker_free_utils.c \
		get_next_line.c \
		get_next_line_utils.c

vpath %.c pushswap_algorithms pushswap_op utils flags parsing bonus

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
	$(CC) $(CFLAGS) $(CDEPS) -c $< -o $@

-include $(OBJS:.o=.d)

$(OBJS_DIR):
	mkdir $@

run: $(NAME)
	./$(NAME) $(FLAGS) $(ARGS)

ifeq ($(USER), charlie)
check: $(NAME)
	$(eval ARG := $(ARGS))
	./$(NAME) $(ARG)
	@./ps_checker.sh $(ARG)
else
check: $(NAME)
	$(eval ARG := $(ARGS))
	./$(NAME) $(ARG) | checker_linux $(ARG)
endif

gdb: $(NAME)
	@gdb --tui --args ./$(NAME) --debug $(FLAGS) $(ARGS)

valgrind vg: $(NAME)
	valgrind ./$(NAME) $(FLAGS) $(ARGS)

valgrindplus vgp: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --keep-stacktraces=alloc-and-free ./$(NAME) $(ARGS)

bonus: $(BONUS)

rbonus: $(BONUS)
	./checker $(ARGS)

bonusgdb: $(BONUS)
	gdb --tui --args ./checker $(ARGS)

$(BONUS): $(OBJS) $(LIBFT) $(PRINTF) | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(BONUS)

clean:
	rm -rf $(OBJS_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

# download:
# 	@curl -o compile_commands.json

re: fclean all

.PHONY: all clean fclean re run gdb valgrind vg valgrindplus vgp bonus check rbonus
