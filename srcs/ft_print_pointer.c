#include "../ft_printf.h"

static int	ft_print_width(int precision, int width, t_format *spec)
{
	char	c;
	int		len;

	len = 0;
	c = ' ';
	if (spec->zero == 1 && precision < width)
		c = '0';
	while (width-- > precision)
		len += write(1, &c, 1);
	return (len);
}

static int	ft_al_left(int prec, int width, unsigned long p, t_format *spec)
{
	int	len;
	int	tmp;

	len = 0;
	len += write(1, "0x", 2);
	len += ft_putnbr_hex(p, spec);
	if (!p && prec > ft_count_hex(p, spec))
	{
		tmp = prec;
		while (tmp-- > ft_count_hex(p, spec))
			len += write(1, "0", 1);
	}
	len += ft_print_width(prec + 2, width, spec);
	return (len);
}

static int	ft_al_right(int prec, int width, unsigned long p, t_format *spec)
{
	int	len;

	len = 0;
	len += ft_print_width(prec + 2, width, spec);
	len += write(1, "0x", 2);
	while (prec-- > ft_count_hex(p, spec))
		len += write(1, "0", 1);
	len += ft_putnbr_hex(p, spec);
	return (len);
}

int	ft_print_pointer(unsigned long pointer, t_format *spec)
{
	int	precision;
	int	width;
	int	len;

	len = 0;
	if (spec->width < 0)
	{
		spec->minus = 1;
		spec->width *= -1;
	}
	if (spec->precision > ft_count_hex(pointer, spec))
		precision = spec->precision;
	else
		precision = ft_count_hex(pointer, spec);
	if (spec->width > precision)
		width = spec->width;
	else
		width = precision;
	if (spec->zero != 1 && width > precision && spec->minus == 1)
		len += ft_al_left(precision, width, pointer, spec);
	else
		len += ft_al_right(precision, width, pointer, spec);
	return (len);
}
