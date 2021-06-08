#include "../ft_printf.h"

static int	ft_intLen(long integer)
{
	int	i;

	i = 0;
	if (integer < 0)
	{
		integer *= -1;
	}
	while (integer > 0)
	{
		integer /= 10;
		i++;
	}
	return (i);
}

static int	ft_print_width(int width, t_format *spec, long integer, int precision)
{
	char	c;
	int		len;

	c = ' ';
	len = 0;
	if (integer < 0)
		width -= 1;
	if (spec->zero == 1 && spec->dot != 1)
		c = '0';
	if (spec->minus == 1)
		c = ' ';
	if (c == '0' && integer < 0)
		write(1, "-", 1);
	while (width > precision)
	{
		if (spec->width > 0)
			write(1, &c, 1);
		else
			write(1, "0", 1);
		width--;
		len++;
	}
	if (integer < 0 && c == ' ')
		write(1, "-", 1);
	while (precision-- > ft_intLen(integer))
	{
		write(1, "0", 1);
		len++;
	}
	return (len);
}

static int	ft_align_left(long integer, int width, t_format *spec, int precision)
{
	int	len;

	len = ft_intLen(integer);
	if (integer < 0)
	{
		integer *= -1;
		width -= 1;
		write(1, "-", 1);
	}
	ft_putnbr(integer);
	len += ft_print_width(width, spec, integer, precision);
	return (len);
}

static int	ft_align_right(long integer, int width, t_format *spec, int precision)
{
	int	len;

	len = ft_intLen(integer);
	len += ft_print_width(width, spec, integer, precision);
	if (integer < 0)
		integer *= -1;
	ft_putnbr(integer);
	return (len);
}

int	ft_print_int(long integer, t_format *spec)
{
	int			len;
	int			width;
	int			precision;

	width = 0;
	precision = 0;
	if (!integer && spec->dot == 1)
		return (0);
	if (spec->precision > ft_intLen(integer))
		precision = spec->precision;
	else
		precision = ft_intLen(integer);
	if (spec->width > precision)
		width = spec->width;
	else
		width = ft_intLen(integer);
	if (spec->minus == 1 && spec->width > 0)
		len = ft_align_left(integer, width, spec, precision);
	else
		len = ft_align_right(integer, width, spec, precision);
	return (len);
}
