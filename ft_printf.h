#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "./libft/libft.h"
typedef struct s_format
{
	int minus;
	int zero;
	int width;
	int dot;
	int precision;
	int type;
}t_format;

int		ft_parser (char **format, va_list ap);
int		ft_print_char(va_list ap, t_format *spec);
int		ft_print_int(va_list ap, t_format *spec);
int		ft_type (char **format, va_list ap, t_format *spec);
int		ft_printf(const char *format, ...);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);

#endif
