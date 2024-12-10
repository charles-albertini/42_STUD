#include "../push_swap.h"

int ft_is_revsort(t_stack *stack_b)
{
	t_stack *check;

	check = stack_b->next;
	while (check != NULL)
	{
		if (*(stack_b->content) < *(check->content) )
			return(1);
		stack_b = stack_b->next;
		check = stack_b->next;
	}
	return(0);
}