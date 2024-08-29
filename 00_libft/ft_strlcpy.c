#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	len = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src [i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}
/*
#include <stdio.h>
int	main()
{
	char src[] = "salut";
	char dest[] = "comment ca va ici";
	printf("%d | %s", ft_strlcpy(dest, src, 3), dest);
}
*/
