#include "../ft_printf.h"

int ft_print_pointer(void *pointer,t_format *spec)
{
	int	len;
	int precision;
	int width;

	len = 0;


	if (spec->precision > ft_strlen(pointer) - 2)
		precision = spec->precision;
	else
		precision = ft_strlen(pointer) - 2;
	if (spec->width > precision)
		width = spec->width;
	else
		width = ft_strlen(pointer);


}