#include "../ft_printf.h"

static int	ft_print_width(int width, t_format *spec, int precision, long
integer)
{
	size_t	len;
	char	c;

	c = ' ';
	if (spec->precision < 0 && width < 0)
		c = '0';
	if (integer < 0)
		width -= 1;
	len = 0;
	if (spec->width < 0 && !integer)
		width = spec->width * -1;
	if (spec->width != 0)
		while (width-- > precision)
			len += write(1, &c, 1);
	return ((int)len);
}

static int	ft_al_left(long integer, int width, t_format *spec, int precision)
{
	size_t	len;
	int		tmp;

	tmp = precision;
	len = ft_count_int(integer);
	if (integer < 0)
	{
		integer *= -1;
		width -= 1;
		len += write(1, "-", 1);
	}
	while (tmp-- > ft_count_int(integer))
		len += write(1, "0", 1);
	ft_putnbr(integer);
	len += ft_print_width(width, spec, precision, integer);
	return ((int)len);
}

static int	ft_al_right(long integer, int width, t_format *spec, int precision)
{
	size_t	len;

	len = ft_count_int(integer);
	if (spec->zero == 1 && spec->width > precision && spec->dot != 1)
	{
		precision = spec->width;
		if (integer < 0)
			precision -= 1;
	}
	len += ft_print_width(width, spec, precision, integer);
	if (integer < 0)
	{
		integer *= -1;
		width -= 1;
		len += write(1, "-", 1);
	}
	while (precision-- > ft_count_int(integer))
		len += write(1, "0", 1);
	ft_putnbr(integer);
	return ((int)len);
}

static int	ft_init_prec(t_format *spec, long integer)
{
	int	precision;

	if (spec->precision < 0)
	{
		spec->dot = 0;
		precision = ft_count_int(integer);
	}
	if (spec->precision > ft_count_int(integer))
		precision = spec->precision;
	else
		precision = ft_count_int(integer);
	return (precision);
}

int	ft_print_int(long integer, t_format *spec)
{
	int			len;
	int			width;
	int			precision;

	len = 0;
	if (!integer && spec->dot == 1 && spec->precision == 0)
	{
		len = ft_print_width(spec->width, spec, spec->precision, integer);
		return (len);
	}
	precision = ft_init_prec(spec, integer);
	if (spec->width < precision)
		width = ft_count_int(integer);
	else
		width = spec->width;
	if (spec->width < 0)
		width = spec->width * -1;
	if ((spec->minus == 1 && spec->width > 0) || spec->width < 0)
		len += ft_al_left(integer, width, spec, precision);
	else
		len += ft_al_right(integer, width, spec, precision);
	return (len);
}
