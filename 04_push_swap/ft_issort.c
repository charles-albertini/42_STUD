#include "push_swap.h"

int ft_issort(t_stack *stack_a)
{
	t_stack *check;

	check = stack_a->next;
	while (check != NULL)
	{
		if (*(stack_a->content) > *(check->content) )
			return(1);
		stack_a = stack_a->next;
		check = stack_a->next;
	}
	return(0);
}
