#include "../ft_printf.h"

static int	ft_print_width(int width, int precision, t_format *spec)
{
	int len;

	len = 0;
	if (width < 0)
		width *= -1;
	while (width > precision)
	{
		if (spec->zero != 1 || spec->minus == 1)
			write(1, " ", 1);
		if (spec->zero == 1 && spec->minus != 1)
			write(1, "0", 1);
		width--;
		len++;
	}
	return (len);
}

static int	ft_precision_init(char *str, t_format *spec)
{
	int	len;

	if (spec->dot != 1)
		len = (int)ft_strlen(str);
	else
	{
		if (spec->precision >= (int)ft_strlen(str) || spec->precision < 0)
			len = (int)ft_strlen(str);
		if (spec->precision < (int)ft_strlen(str) && spec->precision > 0)
			len = spec->precision;
	}
	return (len);
}

int	ft_print_string(char *string, t_format *spec)
{
	int 	len;
	int		width;
	int		precision;

	width = 0;
	if (string == NULL)
		string = "(null)";
	precision = ft_precision_init(string, spec);
	len = precision;
	if (spec->width > precision)
		width = spec->width;
	if (spec->width < 0)
		width = spec->width;
	if (spec->minus == 1 || width < 0)
	{
		write(1, string, precision);
		len += ft_print_width(width, precision, spec);
	}
	else
	{
		len += ft_print_width(width, precision, spec);
		write(1, string, precision);
	}
	return (len);
}
