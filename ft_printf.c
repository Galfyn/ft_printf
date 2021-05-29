#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list argptr;
	char *str;
	unsigned int nb;
	va_start(argptr, format);

	str = va_arg(argptr, char*);
	nb = va_arg(argptr, unsigned int);
	ft_putnbr(nb);
	ft_putstr(str);
	va_end(argptr);
	return (0);
}