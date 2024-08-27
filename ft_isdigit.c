int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int main (void)
{
	char nb = '3';
	if (ft_isdigit(nb) == 1)
		printf("1");
	else
		printf("0");

}
*/
