#include "../ft_printf.h"

static int	ft_intLen(int integer)
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
static void	ft_print_width(int len, t_format *spec, int integer, int precision)
{
	if (integer < 0)
		len -= 2;
	while (len > precision)
	{
		if ((spec->dot == 1 && !spec->width) || (spec->zero == 1 &&
			spec->minus != 1 &&spec->dot != 1))
			write(1, "0", 1);
		else
			write(1, " ", 1);
		len--;
	}
	if (precision > ft_intLen(integer))
		while (precision-- > ft_intLen(integer))
			write(1, "0", 1);
}
static void ft_align_left (int integer, int len, t_format *spec, int precision)
{
	int c;

	c = 0;
	if (integer < 0)
	{
		integer *= -1;
		ft_putchar_fd(1, '-');
	}
	if (integer > 9)
	{
		ft_putnbr(integer / 10);
		ft_putnbr(integer % 10);
	}
	else
	{
		c = integer + 48;
		write(1, &c, 1);
	}
	ft_print_width(len, spec, integer, precision);
}
static void ft_align_right (int integer, int len, t_format *spec, int precision)
{
	int c;

	c = 0;
	ft_print_width(len, spec, integer, precision);
	if (integer < 0)
		integer *= -1;
	if (integer > 9)
	{
		ft_putnbr(integer / 10);
		ft_putnbr(integer % 10);
	}
	else
	{
		c = integer + 48;
		write(1, &c, 1);
	}

}

int	ft_print_int(va_list ap, t_format *spec)
{
	int integer;
	int len;
	int precision;

	integer = va_arg(ap, int);
	len = 0;
	precision = 0;
	if (spec->precision < ft_intLen(integer))
		precision = ft_intLen(integer);
	if (spec->precision > ft_intLen(integer))
		precision = spec->precision;
	if (spec->width > precision)
		len = spec->width;
	if (spec->minus == 1 && spec->width > 0)
		ft_align_left(integer, len, spec, precision);
	else
		ft_align_right(integer, len, spec, precision);
	return (len);
}
