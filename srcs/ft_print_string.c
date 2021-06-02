#include "../ft_printf.h"
static void	ft_print_width(int len, int lenstr, t_format *spec)
{
	while (len > lenstr)
	{
		if (spec->zero == 0 || spec->minus == 1)
			write(1, " ", 1);
		if (spec->zero == 1 && spec->minus == 0)
			write(1, "0", 1);
		len--;
	}
}

int ft_print_string(va_list ap, t_format *spec)
{
	int len;
	int lenstr;
	char *result;

	len = 0;
	result = va_arg(ap, char*);
	lenstr = (int)ft_strlen(result);
	if (spec->precision > lenstr)
		len = lenstr;
	if (spec->precision < lenstr)
		len = spec->precision;
	if (spec->width > len)
		len = spec->width;
	//-------------------------
	if (spec->zero == 1)
		ft_print_width(len, lenstr, spec);
	if (spec->minus == 1)
	{
		ft_putstr(result);
		ft_print_width(len, lenstr, spec);
	}
	if (spec->minus == 0)
		ft_putstr(result);
	return (len);
}