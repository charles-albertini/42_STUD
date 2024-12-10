#include "../push_swap.h"

int ft_findarg(int *nb, t_stack *first)
{
	while (first != NULL)
	{
		if (*nb == *(first -> content))
			return(0);
		first = first -> next;
	}
	return (1);

}
