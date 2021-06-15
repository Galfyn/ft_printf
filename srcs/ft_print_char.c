#include "../ft_printf.h"

static int	ft_print_width(int width, t_format *spec)
{
	size_t	len;

	len = 0;
	while (width-- > 1)
	{
		if (spec->zero == 1 && spec->minus == 0)
			len += write(1, "0", 1);
		else
			len += write(1, " ", 1);
	}
	return ((int)len);
}

int	ft_print_char(int symbol, t_format *spec)
{
	int		width;
	size_t	len;

	width = 1;
	len = 0;
	if (spec->width < 0)
	{
		spec->minus = 1;
		spec->width *= -1;
	}
	if (spec->width > 1)
		width = spec->width;
	if (spec->minus != 1)
	{
		len += ft_print_width(width, spec);
		len += write(1, &symbol, 1);
	}
	else
	{
		len += write(1, &symbol, 1);
		len += ft_print_width(width, spec);
	}
	return ((int)len);
}
