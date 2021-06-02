#include "../ft_printf.h"

static void	ft_struct_init(t_format *spec)
{
	spec->minus = 0;
	spec->zero = 0;
	spec->width = 0;
	spec->dot = 0;
	spec->precision = 0;
	spec->type = 0;
}

int	ft_parser (char **format, va_list ap)
{
	t_format	spec;
	int			len;

	(*format)++;
	ft_struct_init(&spec);
	len = 0;
	while (!ft_isalpha(**format))
	{
		if (**format == '-')
			spec.minus = 1;
		if (**format == '0')
			spec.zero = 1;
		if (ft_isdigit(**format) && spec.dot != 1)
			spec.width = (spec.width * 10) + (**format - '0');
		if (**format == '*' && spec.dot != 1)
			spec.width = va_arg(ap, int);
		if (**format == '.')
			spec.dot = 1;
		if (ft_isdigit(**format) && spec.dot == 1)
			spec.precision = (spec.precision * 10) + (**format - '0');
		if (**format == '*' && spec.dot == 1)
			spec.precision = va_arg(ap, int);
		(*format)++;
	}
	len = ft_type(format, ap, &spec);
	return (len);
}
