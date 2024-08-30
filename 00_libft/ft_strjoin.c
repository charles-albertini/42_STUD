#include "libft.h"

int	ft_all_len(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len;
	int	len_sep;

	i = 0;
	j = 0;
	len = 0;
	len_sep = 0;
	while (strs[i])
	{
		while (strs[i][j])
		{
			j ++;
			len ++;
		}
		j = 0;
		i ++;
	}
	len_sep = ft_strlen(sep);
	len += (len_sep * (size - 1));
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	nbr;
	int	size;

	nbr = 0;
	size = ft_strlen(dest);
	while (src[nbr])
	{
		dest [size + nbr] = src [nbr];
		nbr ++;
	}
	dest [size + nbr] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*out;
	int		len;
	int		i;

	i = 0;
	if (size == 0)
	{
		out = malloc(sizeof(char));
		out[0] = '\0';
		return (out);
	}
	len = ft_all_len(size, strs, sep);
	out = malloc(sizeof(char) * len);
	while (i < size)
	{
		ft_strcat(out, strs[i]);
		if (i < size -1)
			ft_strcat(out, sep);
		i ++;
	}
	return (out);
}
/*
#include <stdio.h>
#include <string.h>
 
int	main(void)
{
	int size = 3;
	//int len;

	//len = ft_all_len(size, (char *[]){"bonjour", "salut", "non"}, "|||");
	//printf("%d \n", len);
	printf("%s \n", ft_strjoin(size, (char *[]){"hello",
	"wo", "this"}, ", "));

}
*/
