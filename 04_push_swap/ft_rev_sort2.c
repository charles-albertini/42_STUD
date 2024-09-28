#include "push_swap.h"

void ft_rev_sort2(t_stack **stack_b)
{
	t_stack *current = *stack_b;
	if (current != NULL && current->next != NULL)
	{
		int a = *(current->content);          // Premier élément
    	int b = *(current->next->content);    // Deuxième élément

    	if (a < b)
       	 ft_sb(stack_b); // Si le premier est plus grand que le deuxième, on les échange
	}

}
