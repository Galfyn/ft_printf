#include "../ft_printf.h"
static void	ft_print_width(int len, int lenstr, t_format *spec)
{
	while (len > lenstr)
	{
		if (spec->zero != 1 || spec->minus == 1)
			write(1, " ", 1);
		if (spec->zero == 1 && spec->minus != 1)
			write(1, "0", 1);
		len--;
	}
}

static int	ft_precesion_init(char *str, t_format *spec)
{
	int	len;

	if (spec->dot != 1)
		len = (int)ft_strlen(str);
	else
	{
		if (spec->precision > (int)ft_strlen(str))
			len = (int)ft_strlen(str);
		if (spec->precision < (int)ft_strlen(str))
			len = spec->precision;
	}
	return (len);
}

int	ft_print_string(va_list ap, t_format *spec)
{
	int		len;
	int		lenP;
	char	*result;

	len = 0;
	result = va_arg(ap, char *);
	if (result == NULL)
		result = "(null)";
	lenP = ft_precesion_init(result, spec);
	if (spec->width > lenP)
		len = spec->width;
	if (spec->minus == 1)
	{
		write(1, result, lenP);
		ft_print_width(len, lenP, spec);
	}
	else
	{
		ft_print_width(len, lenP, spec);
		write(1, result, lenP);
	}
	return (len);
}
