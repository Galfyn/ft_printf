#include "../ft_printf.h"

int ft_type (char **format, va_list ap, t_format *spec)
{
	int len;

	len = 0;
	if (**format == 'd')
		len = ft_print_int(ap, spec);
	if (**format == 'c')
		len = ft_print_char(ap, spec);
	(*format)++;
	return (len);
}