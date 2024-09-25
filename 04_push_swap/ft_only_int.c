#include "push_swap.h"

int ft_only_int (char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= 48 && str[i] <= 57) || (str[i] == 45)))
			return (1);
		i ++;
	}
	return (0);
}


