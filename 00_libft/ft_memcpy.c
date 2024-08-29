#include "libft.h"
// const void pointe vers qqchose qui ne peut pas etre modifie

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest1;
	unsigned char	*src1;

	i = 0;
	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest1);
}
/*
#include <string.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*i;
	char	*j;

	if (argc == 4)
	{
		i = ft_memcpy(argv[1], argv[2], atoi(argv[3]));
		j = memcpy(argv[1], argv[2], atoi(argv[3]));
		printf("Mine : %s\nReal : %s\n", i, j);
	}
	return (0);
}
*/
