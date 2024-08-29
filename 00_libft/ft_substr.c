#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char *str = (unsigned char *)s;
	char *out;
	unsigned int size = ft_strlen ((char *)str);
	unsigned int end = (unsigned int) len;
	size_t i = 0;


	if (start > size)
		return ("");
	if (start + end > size)
		end = size - 1;
	out = malloc(sizeof(char) * ((end - start) + 1));
	if (out == NULL)
		return (NULL);
	while (len > 0)
	{
			out[i] = str[start];
			i ++;
			start ++;
            len --;
	}
	out[start] = '\0';
	return (out);   
}
/*
#include <stdio.h>

int    main(int argc, char **argv)
{
	if (argc == 4)
    	printf("%s\n", ft_substr(argv[1], atoi(argv[2]), atoi(argv[3])));
}
*/
