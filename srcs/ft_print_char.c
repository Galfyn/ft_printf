#include "../ft_printf.h"

static int	ft_print_width(int width, t_format *spec)
{
	int	len;

	len = 0;
	while (width > 1)
	{
		if (spec->zero == 1 && spec->minus == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);

		width--;
		len++;
	}
	return (len);
}

int	ft_print_char(int symbol, t_format *spec)
{
	int		width;
	int		len;

	width = 0;
	len = 1;
	if ((spec->minus == 1 && spec->zero != 1) || (spec->minus == 1
												  && spec->zero == 1))
		write(1, &symbol, 1);
	if (spec->width > 1)
	{
		width = spec->width;
		len += ft_print_width(width, spec);
	}
	if (spec->minus != 1)
		write(1, &symbol, 1);
	return (len);
}
