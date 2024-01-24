NAME	= push_swap
LIBFT	= libft/libft.a
CFLAGS	= -Wall -Wextra -Werror -I.
FILES	= mandatory/push_swap.c mandatory/selection_sort.c \
			mandatory/utils_1.c mandatory/utils_2.c mandatory/utils_3.c \
			mandatory/utils_4.c mandatory/utils_5.c mandatory/utils_6.c \
			mandatory/utils_7.c
OBJ		= $(FILES:.c=.o)
CC		= gcc -fsanitize=address

all: $(NAME)

$(LIBFT):
	cd libft && make

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
