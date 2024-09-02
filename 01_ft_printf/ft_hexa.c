#include "libftprintf.h"

int	ft_hexa(unsigned int nb, char c)
{
	int	len;

	len = 0;
	if (nb >= 16)
		len += ft_hexa(nb / 16, c);
	if (nb % 16 <= 9)
		len += ft_putchar((nb % 16) + '0');
	else
	{
		if (c == 'X')
			len += ft_putchar((nb % 16) + 55);
		else
			len += ft_putchar((nb % 16) + 87);
	}
	return (len);
}
/*
#include <stdio.h>

int main()
{

	int nb = 1234;
	int len;
	char c = 'X';
	len = ft_hexa(nb, c);
	printf("\n%d\n", len);

	return 0;
}
*/
