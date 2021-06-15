#include "../ft_printf.h"

int	ft_count_int(long integer)
{
	int	i;

	i = 0;
	if (integer < 0)
	{
		integer *= -1;
	}
	if (integer == 0)
		return (1);
	while (integer > 0)
	{
		integer /= 10;
		i++;
	}
	return (i);
}
