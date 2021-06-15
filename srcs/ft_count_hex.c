#include "../ft_printf.h"
int	ft_count_hex(unsigned long hex, t_format *spec)
{
	int	i;

	i = 0;
	if (!hex && spec->dot == 1 && spec->precision == 0)
		return (0);
	if (!hex)
		return (1);
	while (hex > 0)
	{
		hex /= 16;
		i++;
	}
	return (i);
}
