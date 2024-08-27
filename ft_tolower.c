#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int    ft_tolower(int c)
{
    if (c >= 65 && c <= 90)
    {
        c = c + 32;
    }
    return (c);
}
