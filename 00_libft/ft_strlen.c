#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>
int main (int argc, char **argv)
{

	if (argc == 2)
	{
	    printf("%ld \n", ft_strlen(argv[1]));
	    printf("%ld \n", strlen(argv[1]));
	}
	return(0);
}
*/
