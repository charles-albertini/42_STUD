#include "libft.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}
/*
#include <stdio.h>

int main (int argc, char **argv)
{

	if (argc == 2)
		printf("%ld \n", ft_strlen(argv[1]));
	return(0);
}
*/
