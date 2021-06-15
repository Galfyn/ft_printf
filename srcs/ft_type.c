#include "../ft_printf.h"
static int	ft_search_spec(char **format)
{
	if (**format == 'c' || **format == 's' || **format == 'd'
		|| **format == 'i' || **format == 'u' || **format == 'p'
		|| **format == 'x' || **format == 'X' || **format == '%')
		return (1);
	else
		return (0);
}

int	ft_type(char **format, va_list ap, t_format *spec)
{
	int	len;

	len = 0;
	if (**format == '%')
		len += ft_print_char('%', spec);
	if (**format == 'd' || **format == 'i')
		len += ft_print_int(va_arg(ap, int), spec);
	if (**format == 'c')
		len += ft_print_char(va_arg(ap, int), spec);
	if (**format == 's')
		len += ft_print_string(va_arg(ap, char *), spec);
	if (**format == 'u')
		len += ft_print_int(va_arg(ap, unsigned int), spec);
	if (**format == 'p')
		len += ft_print_pointer(va_arg(ap, unsigned long ), spec);
	if (**format == 'X')
		spec->type = 'X';
	if (**format == 'x' || **format == 'X')
		len += ft_print_hex(va_arg(ap, unsigned int), spec);
	if (ft_search_spec(format))
		(*format)++;
	return (len);
}
