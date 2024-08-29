#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int  main (void)
{
	char c = '\n';
	if (ft_isprint(c) == 1)
		printf("1");
	else
		printf("0");
}
*/
