NAME	= push_swap
LIBFT	= libft/libft.a
CFLAGS	= -Wall -Wextra -Werror -I.
FILES	= push_swap.c selection_sort.c
OBJ		= $(FILES:.c=.o)
CC		= gcc -fsanitize=address

all: $(NAME)

$(LIBFT):
	cd libft && make

$(PRINTF):
	cd ft_printf && make

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	cd libft && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean all

.PHONY: all clean fclean
