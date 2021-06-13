#include "../ft_printf.h"

static int ft_print_width(int precision, int width, t_format *spec)
{
	char c;
	int len;

	len = 0;
	c = ' ';
	if (spec->zero == 1 && precision < width)
		c = '0';
	while (width-- > precision)
		len += write(1, &c, 1);
	return (len);
}
static int ft_align_left(int precision, int width, unsigned long pointer, t_format *spec)
{
	int len;
	int tmp;

	len = 0;
	len += write(1, "0x", 2);
	len += ft_putnbr_hex(pointer, spec);
	if (!pointer && precision > ft_count_hex(pointer))
	{
		tmp = precision;
		while (tmp-- > ft_count_hex(pointer))
			len += write(1, "0", 1);
	}
	len += ft_print_width(precision + 2, width, spec);
	return (len);
}
static int ft_align_right(int precision, int width, unsigned long pointer, t_format *spec)
{
	int len;

	len = 0;
	len += ft_print_width(precision + 2, width, spec);
	len += write(1, "0x", 2);
	while (precision-- > ft_count_hex(pointer))
		len += write(1, "0", 1);
	len += ft_putnbr_hex(pointer, spec);
	return (len);
}
int ft_print_pointer(unsigned long pointer,t_format *spec)
{
	int precision;
	int width;
	int	len;

	len = 0;
	if (spec->precision > ft_count_hex(pointer))
		precision = spec->precision;
	else
		precision = ft_count_hex(pointer);
	if (spec->width > precision)
		width = spec->width;
	else
		width = precision;
	if (spec->zero != 1 && width > precision && spec->minus == 1)
		len += ft_align_left(precision, width, pointer, spec);
	else
		len += ft_align_right(precision, width, pointer, spec);
	return (len);
}
