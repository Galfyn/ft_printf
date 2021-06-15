NAME =	libftprintf.a

SRC =	./srcs/ft_putnbr.c		./srcs/ft_putstr.c			./srcs/ft_parser.c			./srcs/ft_print_int.c 		\
		./srcs/ft_type.c 		./srcs/ft_print_char.c		./srcs/ft_print_string.c 	./srcs/ft_print_pointer.c 	\
		./srcs/ft_count_hex.c	./srcs/ft_print_hex.c		./srcs/ft_putnbr_hex.c		./srcs/ft_isalpha.c 		\
		./srcs/ft_isdigit.c		./srcs/ft_strlen.c			./srcs/ft_islower.c			./srcs/ft_isupper.c			\
		./srcs/ft_count_int.c	ft_printf.c

OBJ = $(patsubst %.c, %.o, $(SRC))

FLAGS = -Wall -Wextra -Werror

all : $(NAME)
	@echo completed

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $?

%.o : %.c
	@gcc $(FLAGS) -c $< -o $@ -include ft_printf.h 

clean :
	@rm -f $(OBJ)
	@echo clean completed

fclean : clean
	@rm -f $(NAME)

re : fclean all

test : all clean
	gcc main.c libftprintf.a && ./a.out

.PHONY : all clean fclean re test