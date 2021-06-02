#include "../ft_printf.h"

static void	ft_print_width(int len, t_format *spec)
{
	while (len > 1)
	{
		if (spec->zero == 0 || spec->minus == 1)
			write(1, " ", 1);
		if (spec->zero == 1 && spec->minus == 0)
			write(1, "0", 1);
		len--;
	}
}

int	ft_print_char(va_list ap, t_format *spec)
{
	int		len;
	char	*result;

	result = va_arg(ap, char *);
	len = 0;
	if ((spec->minus == 1 && spec->zero == 0) || (spec->minus == 1
			&& spec->zero == 1))
		write(1, &result, 1);
	if (spec->width > 1)
	{
		len = spec->width;
		ft_print_width(len, spec);
	}
	if (spec->minus == 0)
		write(1, &result, 1);
	return (len);
}
