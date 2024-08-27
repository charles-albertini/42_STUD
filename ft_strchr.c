#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
        i ++;
    return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;

    str = (unsigned char *)s;
	if (c == '\0')
	{
		i = ft_strlen((char *)s);
		return ((char *)&str[i]);
	}
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}


#include <stddef.h>
#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv)
{
	char	*i;
	char	*j;

	if (argc == 3)
	{
		i = ft_strchr(argv[1], atoi (argv[2]));
		j = strchr(argv[1], atoi (argv[2]));
		printf("Mine : %s\nReal : %s\n", i, j);
	}
	return (0);
}



