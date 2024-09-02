#include "libftprintf.h"

int	ft_isformat(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
	{
		return (1);
	}
	return (0);
}
/*
#include <stdio.h>

int main (void)
{
    char c = 'l';
    printf("%d\n", ft_isformat(c));
}
*/
