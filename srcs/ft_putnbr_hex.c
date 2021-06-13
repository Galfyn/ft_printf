#include "../ft_printf.h"
int ft_putnbr_hex(unsigned long pointer, t_format *spec)
{
	unsigned long i;
	unsigned long nb;
	char *c;
	int len;

	i = 1;
	c = "0123456789abcdef";
	nb = pointer;
	len = 0;
	if (spec->type == 'X')
		c = "0123456789ABCDEF";
	if (!pointer && spec->precision == 0 && spec->dot == 1)
		return (0);
	while (nb > 15)
	{
		nb /= 16;
		i *= 16;

	}
	while (i > 0)
	{
		nb = pointer / i;
		len += write(1,&c[nb], 1);
		pointer %= i;
		i /= 16;
	}
	return (len);
}