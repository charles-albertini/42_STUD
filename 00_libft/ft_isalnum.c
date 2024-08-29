#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int main (void)
{
	char nb = '3';
	char nb2 = ';';
	if ((ft_isalnum(nb) == 1) && (ft_isalnum(nb2) == 1))
		printf("1");
	else
		printf("0");

}
*/
