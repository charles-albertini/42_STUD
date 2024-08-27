#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int ft_intlen (long int n)
{
	long int nb = 0;

	while (n > 0)
	{
		n = n/ 10;
		nb ++;
	}
	return (nb);
}

char *positiv(long int n)
{
	int size = ft_intlen(n);
	int size_save = size;
	char *out;

	out = malloc (sizeof(char) * (size + 1));
	if (out == NULL)
		return (NULL);
	while (size > 0)
	{
		out [size - 1] = n % 10 + '0';
		n = n / 10;
		size --;
	}
	out [size_save] = '\0';
	return (out);
}
char *negativ(long int n)
{
    n *= -1;
	int size = ft_intlen(n);
	int size_save = size;
	char *out;

	out = malloc (sizeof(char) * (size + 2));
	if (out == NULL)
		return (NULL);
	out [0] = '-';
	while (size > 0)
	{
		out [size] = n % 10 + '0';
		n = n / 10;
		size --;
	}
	out [size_save + 1] = '\0';
	return (out);
}
char	*ft_itoa(int n)
{
	char			*out;
	long int	nb;

	nb = (long int)n;
	if (nb == 0)
	{
		out = malloc(sizeof(char) * 2);
		if (out == NULL)
			return (NULL);
		out[0] = '0';
		out[1] = '\0';
	}
	else if (n < 0)
	{
		out = negativ(nb);
	}
	else
	{
		out = positiv(nb);
	}
	return (out);
}

int    main(int argc, char **argv)
{
    
	if (argc == 2)
	printf("%s\n", ft_itoa(atoi(argv[1])));
	
    return (0);
}

