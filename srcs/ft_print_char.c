#include "../ft_printf.h"

int ft_print_char(va_list ap, t_format *spec)
{
	int	len;
	char *result;

	result = va_arg(ap, char*);
	len = 0;

	if (spec->minus == 1 && spec->zero == 0)
		write(1, &result, 1);
	if (spec->width > 1)
	{
		len = spec->width;
		while (len > 1)
		{
			write(1, " ", 1);
			len--;
		}
	}
	if (spec->width > 1 && spec->zero == 1)
		len = spec->width;
		while (len > 1)
		{
			write(1, "0", 1);
			len--;
		}
	if (spec->minus == 0)
		write(1, &result, 1);
	return (len);
}