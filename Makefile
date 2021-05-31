NAME =	libftprintf.a

SRC =	./srcs/ft_putnbr.c	./srcs/ft_parser.c	./srcs/ft_print_int.c ./srcs/ft_type.c	\
		ft_printf.c

OBJ = $(patsubst %.c, %.o, $(SRC))

FLAGS = -Wall -Wextra -Werror

all : libft_check $(NAME)
	@echo completed
$(NAME) : $(OBJ)
	@ar rcs $(NAME) $?

%.o : %.c
	@gcc $(FLAGS) -c $< -o $@ -include ft_printf.h

libft_check :
	@make -C ./libft

libft_clean :
	@make clean -C ./libft


clean : libft_clean
	@rm -f $(OBJ)
	@echo clean completed

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re libft_check libft_clean