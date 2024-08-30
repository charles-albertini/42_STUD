#include "libft.h"

int	ft_find(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_creat(char *str, int first, int last)
{
	char	*out;
	int		i;
	int		size;

	size = last - first;
	out = malloc(sizeof(char) * (size + 1));
	i = 0;
	while (i < size)
	{
		out[i] = str[first + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	**ft_split(char *str, char *charset)
{
	char	**out;
	int		first;
	int		i_out;
	int		i;

	i = 0;
	first = 0;
	i_out = 0;
	out = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	while (str[i])
	{
		while (str[i] && ft_find(str[i], charset) == 1)
			i++;
		first = i;
		while (str[i] && ft_find(str[i], charset) == 0)
			i++;
		if (first != i)
		{
			out[i_out] = ft_creat(str, first, i);
			i_out ++;
		}
	}
	out[i_out] = 0;
	return (out);
}
/*
 
#include <stdio.h>
 
int	main(void)
{
	char	**out;
	int		i;

	out = ft_split("salut comment ca vaaaaa", "au");
	i = 0;
	while (out[i])
	{
		printf("%s\n", out[i]);
		free (out[i]);
		i++;
	}
	free (out[i + 1]);		
}
*/
