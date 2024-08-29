#include "libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	nbr;

	nbr = 0;
	while (src[nbr])
	{
		dest [nbr] = src [nbr];
		nbr ++;
	}
	dest [nbr] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*cpy;

	cpy = malloc(ft_strlen(src) + 1);
	if (cpy == NULL)
		return (NULL);
	cpy = ft_strcpy(cpy, src);
	return (cpy);
}

/*
#include <stdio.h>
int	main (void)
{
	char	*str = "phrase a copier";
	char	*strcpy;

	strcpy = ft_strdup(str);
	printf("%s \n", strcpy);
	free(strcpy);		
}
*/
