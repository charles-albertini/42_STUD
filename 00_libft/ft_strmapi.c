#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				len;
	char			*s2;

	i = 0;
	len = 0;
	while (s[len] != '\0')
		len++;
	s2 = malloc(sizeof(char) * len + 1);
	if (s2 == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		s2[i] = f(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/*
 
#include <string.h>
#include <stdio.h>
 
char    f(unsigned int, char c)
{
    char    str;

    (void)i;
    str = c - 32;
    return (str);
}
int    main(int argc, char **argv)
{
    char    *str2;

    if (argc == 2)
    {
        str2 = ft_strmapi(argv[1], *f);
        printf("%s\n", str2);
    }
    return (0);
}
*/
