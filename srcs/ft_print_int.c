#include "../ft_printf.h"

static int	ft_intLen(long integer)
{
	int	i;

	i = 0;
	if (integer < 0)
		integer *= -1;
	while (integer > 9)
	{
		integer /= 10;
		i++;
	}
	i++;
	return (i);
}

static void	ft_print_width(int len, t_format *spec, long integer, int precision)
{
	char	c;

	c = ' ';
	if (integer < 0)
		len -= 1;
	if (spec->zero == 1 && spec->dot != 1)
		c = '0';
	if (spec->minus == 1)
		c = ' ';
	if (c == '0' && integer < 0)
		write(1, "-", 1);
	while (len > precision)
	{
		if (spec->width > 0)
			write(1, &c, 1);
		else
			write(1, "0", 1);
		len--;
	}
	if (integer < 0 && c == ' ')
		write(1, "-", 1);
	while (precision-- > ft_intLen(integer))
		write(1, "0", 1);
}

static void	ft_align_left(long integer, int len, t_format *spec, int precision)
{
	if (integer < 0)
	{
		integer *= -1;
		len -= 1;
		write(1, "-", 1);
	}
	ft_putnbr(integer);
	ft_print_width(len, spec, integer, precision);
}

static void	ft_align_right(long integer, int len, t_format *spec, int precision)
{
	ft_print_width(len, spec, integer, precision);
	if (integer < 0)
		integer *= -1;
	ft_putnbr(integer);
}

int	ft_print_int(va_list ap, t_format *spec)
{
	long		integer;
	int			len;
	int			precision;

	integer = va_arg(ap, int);
	len = 0;
	precision = 0;
	if (!integer && spec->dot == 1)
		return (0);
	if (spec->precision < ft_intLen(integer))
		precision = ft_intLen(integer);
	else
		precision = spec->precision;
	if (spec->width > precision)
		len = spec->width;
	else
		len = ft_intLen(integer);
	if (spec->minus == 1 && spec->width > 0)
		ft_align_left(integer, len, spec, precision);
	else
		ft_align_right(integer, len, spec, precision);
	return (len);
}
