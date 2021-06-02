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

int	ft_print_int(va_list ap, t_format *spec)
{
	int	integer;
	int	len;
	int	result;

	integer = va_arg(ap, int);
	len = 0;
	if (spec->precision < ft_intLen(integer))
		len = ft_intLen(integer);
	else
		len = spec->precision;
	if (spec->width > len)
		len = spec->width;
	result = len;
	while (len > spec->precision && len > ft_intLen(integer))
	{
		if (spec->dot == 0 && spec->zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		len--;
	}
	while (len > ft_intLen(integer))
	{
		write(1, "0", 1);
		len--;
	}
	if (spec->precision == 0 && spec->dot == 1 && integer == 0)
		write(1, " ", 1);
	else
		ft_putnbr(integer);
	return (result);
}
