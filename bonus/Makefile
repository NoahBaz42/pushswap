NAME = checker

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -I.
CDEPS =  -MMD -MP

LIBFT_DIR = ../libft_pushswap
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ../ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

INCLUDES = -I.. -I.

SRCS = checker.c \
		get_next_line_utils.c \
		get_next_line.c \

vpath %.c GNL

OBJS_DIR = objs/
OBJ = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_DIR),$(OBJ))

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(OBJS_DIR)%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CDEPS) -c $(INCLUDES) $< -o $@

-include $(OBJS:.o=.d)

$(OBJS_DIR):
	mkdir $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re