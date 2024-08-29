#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	nbr;

	nbr = 0;
	while ((s1[nbr] || s2[nbr]) && nbr < n)
	{
		if (s1[nbr] < s2[nbr])
			return (-1);
		if (s1[nbr] > s2[nbr])
			return (1);
		nbr ++;
	}
	return (0);
}
