NAME = libft.a

SRC = 	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strmapi.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

OBJ = $(SRC:.c=.o)

SOURCES = $(SRC)
OBJECTS = $(OBJ)
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
CFLAGS_SAN = -fsanitize=address
CFLAGS_BSD = -lbsd

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o  $@

diff:
	$(info the status of the repository and the volume of per-file changes:)
	@git status
	@git diff --stat

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

push: fclean
	git add .
	git commit -m ""
	git push


.PHONY: all clean fclean re diff push
