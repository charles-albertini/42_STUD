#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*
void    f(unsigned int, char *s)
{
    int    i;

    i = 0;
    while (s[i] != '\0')
    {
        write(1, &s[i], 1);
        i++;
    }
    write(1, "\n", 1);
}
int    main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_striteri(argv[1], f);
    }
    return (0);
}
*/
