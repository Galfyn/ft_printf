#include "ft_printf.h"

int printf(const char *format, ...)
{
	va_list argptr;
	char *str;
	unsigned int nb;
	va_start(argptr, format);

	str = va_arg(argptr, char*);
	nb = va_arg(argptr, int);



}