NAME = libftprintf.a

SRC = ft_printf.c \
      ft_put_char.c \
      ft_put_string.c \
      ft_put_nbr.c \
      ft_put_unb.c \
      ft_decToHex.c \
      ft_print_ptr.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) .
	$(AR) $(NAME) $(OBJ) libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) libft.a
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re