NAME =	libftprintf.a

SRC =	./srcs/ft_putnbr.c	./srcs/ft_putstr.c	./srcs/ft_parser.c	./srcs/ft_print_int.c ./srcs/ft_type.c \
		./srcs/ft_print_char.c	./srcs/ft_print_string.c	ft_printf.c

OBJ = $(patsubst %.c, %.o, $(SRC))

FLAGS = -Wall -Wextra -Werror

all : $(NAME)
	@echo completed
	@make -C ./libft
$(NAME) : $(OBJ)
	@ar rcs $(NAME) $?

%.o : %.c
	@gcc $(FLAGS) -c $< -o $@ -include ft_printf.h

clean :
	@rm -f $(OBJ)
	@make clean -C ./libft
	@echo clean completed

fclean : clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re : fclean all

test : all clean
	gcc main.c libftprintf.a libft/libft.a && ./a.out

.PHONY : all clean fclean re