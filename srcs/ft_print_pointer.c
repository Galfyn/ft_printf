#include "../ft_printf.h"

static int ft_count_pointer(unsigned long pointer)
{
	int i;

	i = 0;
	if (!pointer)
		return (1);
	while (pointer > 0)
	{
		pointer /= 16;
		i++;
	}
	return (i);
}

static void ft_putnbr_pointer(unsigned long pointer)
{
	unsigned long i;
	unsigned long nb;
	char *c;

	i = 1;
	c = "0123456789abcdef";
	nb = pointer;
	while (nb > 15)
	{
		nb /= 16;
		i *= 16;

	}
	while (i > 0)
	{
		 nb = pointer / i;
		 write(1,&c[nb], 1);
		 pointer %= i;
		 i /= 16;
	}
}

static void ft_print_width(int precision, int width, t_format *spec)
{

	while (width-- > precision)
	{
		if (spec->zero == 1 && precision < width)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
}
int ft_print_pointer(va_list ap,t_format *spec)
{
	int	len;
	int precision;
	int width;
	unsigned long pointer;


	pointer = va_arg(ap, unsigned long);
	len = 0;
	if (spec->precision > ft_count_pointer(pointer))
		precision = spec->precision;
	else
		precision = ft_count_pointer(pointer);
	if (spec->width > precision)
		width = spec->width;
	else
		width = precision;

	if (spec->zero != 1 && width > precision && spec->minus == 1)
	{
		write(1, "0x", 2);
		ft_putnbr_pointer(pointer);
		ft_print_width(precision + 2, width, spec);
	}
	else
	{
		ft_print_width(precision + 2, width, spec);
		write(1, "0x", 2);
		while (precision-- > ft_count_pointer(pointer))
			write(1, "0", 1);
		ft_putnbr_pointer(pointer);
	}

	return (len);
}