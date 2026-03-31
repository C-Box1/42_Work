NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = \
    ft_split.c \
    ft_simple_algorithm2.c \
    ft_simple_algorithm.c \
    ft_print_benchmarks.c \
    ft_medium_algorithm.c \
    ft_complex_algorithm.c \
    parsing_utils.c \
    main.c \
    parsing_utils3.c \
    parsing_utils2.c \
    push_swap1.c \
    push_swap2.c \
    utils.c \
    utils_reverse_rotate.c \
    utils_push.c \
    utils2.c \
    utils_rotate.c \
    utils_swap.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re