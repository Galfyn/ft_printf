#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		length;
	char	*temp;

	length = 0;
	temp = (char *)format;
	va_start(argptr, format);
	while (*temp)
	{
		if (*temp == '%')
			length = ft_parser(&temp, argptr);
		if (*temp)
		{
			write(1, temp, 1);
			temp++;
			length++;
		}
	}
	va_end (argptr);
	return (length);
}
