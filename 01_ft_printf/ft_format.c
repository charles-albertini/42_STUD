#include "libftprintf.h"

int	ft_format(va_list *args, char c)
{
	int					len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(*args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(*args, char *));
	else if (c == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_ptr(va_arg(*args, unsigned long int));
	}
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(*args, int));
	else if (c == 'u')
		len += ft_putnbrui(va_arg(*args, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_hexa(va_arg(*args, unsigned int), c);
	else if (c == '%')
		len += ft_putchar(c);
	return (len);
}
