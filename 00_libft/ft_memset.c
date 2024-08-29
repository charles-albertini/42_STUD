#include "libft.h"

/*
 Un pointeur void est utiliser quand on ne connait pas d'avance sur quoi va pointer le pointeur.
 C'est pour ca qu'apres on creer s2 en unsigned char.
 unsigned char est un entier non signé de 8 bits (0 à 255)
*/

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
        str[i] = c;
		i++;
	}
	return (s);
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
		i = ft_memset(argv[1], *argv[2], atoi(argv[3]));
		j = memset(argv[1], *argv[2], atoi(argv[3]));
		printf("Mine : %s\nReal : %s\n", i, j);
	}
	return (0);
}
*/
