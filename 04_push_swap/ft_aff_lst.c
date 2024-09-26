#include "push_swap.h"
#include <stdio.h>

void aff_lst(t_stack *lst)
{
	if (lst == NULL)
	{
		printf("liste vide\n");
		return;
	}
	while (lst != NULL)
	{
		if (lst -> content == NULL)
			printf("NULL\n");
		else
			printf("%d\n", *(int *)(lst -> content));
		lst = lst -> next;
	}
}
