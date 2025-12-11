NAME = libftprintf.a

SRC = ft_printf.c\
	ft_put_char.c\
	ft_put_string.c\
	ft_put_nbr.c\
	ft_put_unb.c\
	ft_decToHex.c\
	ft_print_ptr.c
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus