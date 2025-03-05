#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>


int ft_isformat(char c)
{
	if (c == 'd' || c == 'x' || c =='s')
		return(1);
	return(0);
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return(1);
}

int ft_putstr(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		write(1, &"(null)", 6);
		return(6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return(i);
}

int ft_putnbr(int nb)
{
	int len  =0;

	if (nb == -2147483648)
	{
		write(1, &"-2147483648", 11);
		return(11);
	}
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = nb * (-1);
	}
	if (nb > 9)
		len += ft_putnbr(nb / 10);
	len += ft_putchar((nb % 10) + '0');
	return(len);
}

int ft_hexa(unsigned int nb)
{
	int len =0;

	if (nb > 16)
		len+=ft_hexa(nb / 16);
	if ((nb % 16) < 9)
		len +=ft_putchar((nb % 16) + '0');
	else 
		len +=ft_putchar((nb % 16) + 87);
	return(len);
}

int ft_format(va_list *args, char c)
{
	int len = 0;

	if (c == 'd')
		len += ft_putnbr(va_arg(*args, int));
	if (c == 's')
		len += ft_putstr(va_arg(*args, char *));
	if (c == 'x')
		len += ft_hexa(va_arg(*args, unsigned int));
	return(len);
}
int ft_printf(char *format, ...)
{
	int len = 0;
	int i = 0;
	va_list args;

	va_start(args, format);
	// if (!args)
	// 	return(-1);
	
	while (format[i])
	{
		if (format[i] == '%' && ft_isformat(format[i+1]) == 1)
		{
			len += ft_format(&args, format[i + 1]);
			i++;
		}
		else
			len+= ft_putchar(format[i]);
		i++;
		if (len == -1)
			return(-1);
	}
	va_end(args);
	return(len);
}

int	main(void)
{
	int nb = 0;
	int nb2 = 45;
	char *str = "salut";
	int hex = 1234;
	
	printf("%d\n", ft_printf("Mine : %d %d\n", nb, nb2));
	printf("%d\n", printf("Real : %d %d\n", nb, nb2));
    
	printf("%d\n", ft_printf("Mine : %s \n", str));
	printf("%d\n", printf("Real : %s \n", str));
    
	printf("%d\n", ft_printf("Mine : %d \n", nb));
	printf("%d\n", printf("Real : %d \n", nb));
    
	printf("%d\n", ft_printf("Mine : %x \n", hex));
	printf("%d\n", printf("Real : %x \n", hex));
	
	return (0);
}

