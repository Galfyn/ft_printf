#include "../ft_printf.h"

static int	ft_print(unsigned long pointer, unsigned long i, t_format *spec)
{
	char			*c;
	unsigned long	nb;
	int				len;

	len = 0;
	c = "0123456789abcdef";
	if (spec->type == 'X')
		c = "0123456789ABCDEF";
	while (i > 0)
	{
		nb = pointer / i;
		len += write(1, &c[nb], 1);
		pointer %= i;
		i /= 16;
	}
	return (len);
}

int	ft_putnbr_hex(unsigned long pointer, t_format *spec)
{
	unsigned long	i;
	unsigned long	nb;
	int				len;

	i = 1;
	nb = pointer;
	len = 0;
	if (!pointer && spec->precision == 0 && spec->dot == 1)
		return (0);
	while (nb > 15)
	{
		nb /= 16;
		i *= 16;
	}
	len += ft_print(pointer, i, spec);
	return (len);
}
