#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int main (void)
{
	char a = ';';
	if (ft_isalpha(a) == 1)
		printf("1");
	else
		printf("0");

}
*/
