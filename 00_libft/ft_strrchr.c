#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*s2;

	s2 = (unsigned char *)s;
	if (c == '\0')
	{
		i = ft_strlen((char *)s);
		return ((char *)&s2[i]);
	}
	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s2[i]);
		}
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv)
{
	char	*i;
	char	*j;

	if (argc == 3)
	{
		i = ft_strrchr(argv[1], atoi (argv[2]));
		j = strrchr(argv[1], atoi (argv[2]));
		printf("Mine : %s\nReal : %s\n", i, j);
	}
	return (0);
}
*/