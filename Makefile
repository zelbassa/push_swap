NAME	= push_swap
NAME_B	= checker
LIBFT	= libft/libft.a
CFLAGS	= -Wall -Wextra -Werror -I.
FILES	= mandatory/push_swap.c mandatory/selection_sort.c \
			mandatory/utils_1.c mandatory/utils_2.c mandatory/utils_3.c \
			mandatory/utils_4.c mandatory/utils_5.c mandatory/utils_6.c \
			mandatory/utils_7.c

B_FILES	= bonus/checker.c bonus/get_next_line.c bonus/get_next_line_utils.c \
			bonus/utils_1.c bonus/utils_2.c bonus/utils_3.c \

OBJ		= $(FILES:.c=.o)

OBJ_B	= $(B_FILES:.c=.o)

CC		= gcc -fsanitize=address

all: $(NAME)

$(LIBFT):
	cd libft && make

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)

bonus: $(NAME_B)

$(NAME_B): $(OBJ_B) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_B) -Llibft -lft -o $(NAME_B)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_B)
	cd libft && make clean

fclean: clean
	rm -f $(NAME) $(NAME_B)
	cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re bonus