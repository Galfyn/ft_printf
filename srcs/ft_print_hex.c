#include "../ft_printf.h"
static int ft_count_hex2(unsigned long hex, t_format *spec)
{
	int i;

	i = 0;
	if (!hex && spec->dot == 1 && spec->precision == 0)
		return (0);
	if (!hex)
		return (1);
	while (hex > 0)
	{
		hex /= 16;
		i++;
	}
	return (i);
}
static int ft_print_width(int precision, int width, t_format *spec)
{
	char c;
	int len;

	len = 0;
	c = ' ';
	if (spec->zero == 1 && spec->dot != 1)
		c = '0';
	while (width-- > precision)
		len += write(1, &c, 1);
	return (len);
}
static int ft_align_left(int precision, int width, unsigned long hex, t_format *spec)
{
	int len;
	int tmp;

	len = 0;
	if (precision > ft_count_hex2(hex, spec))
	{
		tmp = precision;
		while (tmp-- > ft_count_hex2(hex, spec))
			len += write(1, "0", 1);
	}
	len += ft_putnbr_hex(hex, spec);
	len += ft_print_width(precision, width, spec);
	return (len);
}
static int ft_align_right(int precision, int width, unsigned long hex, t_format *spec)
{
	int len;

	len = 0;
	len += ft_print_width(precision, width, spec);
	while (precision-- > ft_count_hex2(hex, spec))
		len += write(1, "0", 1);
		len += ft_putnbr_hex(hex, spec);
	return (len);
}
int ft_print_hex(unsigned long hex,t_format *spec)
{
	int precision;
	int width;
	int	len;

	len = 0;

	if (spec->precision > ft_count_hex2(hex, spec))
		precision = spec->precision;
	else
		precision = ft_count_hex2(hex, spec);
	if (spec->width > precision)
		width = spec->width;
	else
		width = precision;
	if (width > precision && spec->minus == 1)
		len += ft_align_left(precision, width, hex, spec);
	else
		len += ft_align_right(precision, width, hex, spec);
	return (len);
}