#include "../ft_printf.h"
static int	ft_print_width(int precision, int width, t_format *spec)
{
	char	c;
	int		len;

	len = 0;
	c = ' ';
	if (spec->zero == 1 && spec->dot != 1)
		c = '0';
	while (width-- > precision)
		len += write(1, &c, 1);
	return (len);
}

static int	ft_al_left(int prec, int width, unsigned int hex, t_format *spec)
{
	int	len;
	int	tmp;

	len = 0;
	if (prec > ft_count_hex(hex, spec))
	{
		tmp = prec;
		while (tmp-- > ft_count_hex(hex, spec))
			len += write(1, "0", 1);
	}
	len += ft_putnbr_hex(hex, spec);
	len += ft_print_width(prec, width, spec);
	return (len);
}

static int	ft_al_right(int prec, int width, unsigned int hex, t_format *spec)
{
	int	len;

	len = 0;
	len += ft_print_width(prec, width, spec);
	while (prec-- > ft_count_hex(hex, spec))
		len += write(1, "0", 1);
	len += ft_putnbr_hex(hex, spec);
	return (len);
}

int	ft_print_hex(unsigned int hex, t_format *spec)
{
	int	precision;
	int	width;
	int	len;

	len = 0;
	if (spec->precision < 0)
		spec->dot = 0;
	if (spec->precision > ft_count_hex(hex, spec))
		precision = spec->precision;
	else
		precision = ft_count_hex(hex, spec);
	if (spec->width > precision)
		width = spec->width;
	else
		width = precision;
	if (spec->width < 0)
		width = spec->width * -1;
	if (width > precision && spec->minus == 1)
		len += ft_al_left(precision, width, hex, spec);
	else
		len += ft_al_right(precision, width, hex, spec);
	return (len);
}
