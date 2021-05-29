NAME =	libftprintf.a

SRC =	ft_printf.c	./srcs/ft_putnbr.c	./srcs/ft_putstr.c

OBJ = $(patsubst %.c, %.o, $(SRC))

FLAGS = -Wall -Wextra -Werror

all : libft_check $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c
	gcc $(FLAGS) -c $< -o $@ -include ft_printf.h

libft_check :
	make -C ./libft

libft_clean :
	make clean -C ./libft


clean : libft_clean
	rm -f $(NAME) $(OBJ) $(LIBFT)

fclean : clean
	rm -f $(NAME)

re :
	fclean all

.PHONY :
	all clean fclean re libft_check libft_clean