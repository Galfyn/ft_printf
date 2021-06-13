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

int		ft_printf(const char *format, ...);

int		ft_type (char **format, va_list ap, t_format *spec);
int		ft_parser (char **format, va_list ap);

int		ft_print_string(char *string, t_format *spec);
int		ft_print_pointer(unsigned long pointer, t_format *spec);
int		ft_print_char(int symbol, t_format *spec);
int		ft_print_int(long integer, t_format *spec);
int		ft_print_hex(unsigned long hex, t_format *spec);


void	ft_putstr(char *str);
void	ft_putnbr(long long nbr);
int		ft_count_hex(unsigned long pointer);
int		ft_putnbr_hex(unsigned long pointer, t_format *spec);


#endif
