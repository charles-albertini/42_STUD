#include "libft.h"

char *ft_strnstr(const char *str1, const char *str2, size_t len)
{
    size_t      i;
    size_t      j;
    size_t      k;
    unsigned char *str;
    unsigned char *find;
    
    i = 0;
    j = 0;
    str = (unsigned char *)str1;
    find = (unsigned char *)str2;
    if (find[j] == '\0')
        return((char *)str);
    while (str[i] && i < len)
    {
        if (str[i] == find[j])
        {
            k = i;
            while (str[k] == find[j])
            {
                j ++;
                k ++;
                if (find[j] == '\0')
                    return((char *)&str[i]);
            }
        }
        j = 0;
        i ++;
    }
    return(NULL);
}
/*
#include <string.h>
#include <stdio.h>

int    main(int argc, char **argv)
{
    if (argc == 4)
    {
        char *result = strnstr(argv[1], argv[2], atoi(argv[3]));
        char *result2 = ft_strnstr(argv[1], argv[2], atoi(argv[3]));
        printf("real : %s\n", result);
        printf("mine : %s\n", result2);
    }
    return (0);
}
*/

