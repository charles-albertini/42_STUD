#include "push_swap.h"

void ft_sort2(t_stack **stack_a)
{
	t_stack *current = *stack_a;
	if (current != NULL && current->next != NULL)
	{
		int a = *(current->content);          // Premier élément
    	int b = *(current->next->content);    // Deuxième élément

    	if (a > b)
        	ft_sa(stack_a); // Si le premier est plus grand que le deuxième, on les échange
	}
    
}
