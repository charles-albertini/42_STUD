#include "push_swap.h"
#include <stdio.h>

void aff_lst(t_stack *lst)
{
	while (lst != NULL)
	{
		printf("%d\n", *(int *)(lst -> content));
		lst = lst -> next;
	}
}
