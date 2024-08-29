#include "libft.h"

int	ft_atoi(char *str)
{
	int	nbr;
	int	neg;
	int	out;

	nbr = 0;
	neg = 1;
	out = 0;
	while (str[nbr] == ' ' || str[nbr] == '\f' || str[nbr] == '\n'
		|| str[nbr] == '\r' || str[nbr] == '\t' || str[nbr] == '\v')
	{
		nbr ++;
	}
	while (str[nbr] == '+' || str[nbr] == '-')
	{
		if (str[nbr] == '-')
			neg = neg * (-1);
		nbr ++;
	}
	while (str[nbr] >= '0' && str[nbr] <= '9')
	{
		out = out * 10;
		out = out + str[nbr] - '0';
		nbr ++;
	}
	return (neg * out);
}
/*
#include <stdio.h>
 
int main (void)
{	
	printf("%d \n", ft_atoi("   ---+--+1234ab567"));
}
*/
