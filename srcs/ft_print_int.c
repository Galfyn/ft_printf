#include "../ft_printf.h"

int static	ft_intLen(int integer)
{
	int	i;

	i = 0;
	while (integer > 9)
	{
		integer /= 10;
		i++;
	}
	i++;
	return (i);
}
void static ft_print_width(int len, t_format *spec, int integer)
{
	while (len > ft_intLen(integer))
	{
		if (spec->dot == 0 && spec->zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		len--;
	}
}
static void ft_print_int_space(int integer, int len, t_format *spec)
{
	ft_putnbr(integer);
	ft_print_width(len, spec, integer);
}
static void ft_print_space_int(int integer, int len, t_format *spec)
{
	ft_print_width(len, spec, integer);
	ft_putnbr(integer);
}
int	ft_print_int(va_list ap, t_format *spec)
{
	int integer;
	int len;
	int result;

	integer = va_arg(ap, int);
	len = 0;
	if (spec->precision < ft_intLen(integer))
		len = ft_intLen(integer);
	if (spec->precision > ft_intLen(integer))
		len = spec->precision;
	if (spec->width > len)
		len = spec->width;
	if (spec->minus == 1)
		ft_print_int_space(integer, len, spec);
	if (spec->zero == 1 && spec->dot != 1)
		ft_print_space_int(integer, len, spec);
	if (spec->width > ft_intLen(integer) && spec->minus != 1 && spec->zero != 1)
		ft_print_space_int(integer, len, spec);
	if (spec->zero == 1 && spec->dot == 1 && spec->minus != 1)
		ft_print_space_int(integer, len, spec);

	result = len;
	return (result);
}
