NAME	= push_swap
NAME_B	= checker
LIBFT	= libft/libft.a
CFLAGS	= -Wall -Wextra -Werror -I.
FILES	= mandatory/push_swap.c mandatory/selection_sort.c \
			mandatory/utils_1.c mandatory/utils_2.c mandatory/utils_3.c \
			mandatory/utils_4.c mandatory/utils_5.c mandatory/utils_6.c \
			mandatory/utils_7.c libft/ft_putstr.c libft/ft_atoi.c \
			libft/ft_split.c libft/ft_isdigit.c libft/ft_strlen.c \
			libft/ft_strlcpy.c libft/ft_substr.c libft/ft_strdup.c \
			libft/ft_strcmp.c libft/ft_isint.c libft/ft_bzero.c

B_FILES	= bonus/checker.c bonus/utils_1.c bonus/utils_2.c bonus/utils_3.c \
			bonus/get_next_line.c bonus/get_next_line_utils.c \
			bonus/utils_4.c bonus/utils_5.c

OBJ		= $(FILES:.c=.o)

OBJ_B	= $(B_FILES:.c=.o)

CC		= cc -fsanitize=address

$(LIBFT):
	cd libft && make

all: $(NAME)

bonus: $(NAME_B)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft  -o $(NAME)

$(NAME_B): $(OBJ_B) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_B) -Llibft -lft -o $(NAME_B)

clean:
	rm -f $(OBJ) $(OBJ_B)
	cd libft && make clean

fclean: clean
	rm -f $(NAME) $(NAME_B)
	cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re
