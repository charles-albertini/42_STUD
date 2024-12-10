
#include "push_swap.h"

void ft_sort_pivot(t_stack **stack_a, t_stack **stack_b, int pivot)
{
	int size = ft_lstsize(*stack_a);
    int count = 0;

    // Déplacer les éléments vers stack_b en fonction du pivot
    while (count < size) {
        if ((*(*stack_a)->content) <= pivot)
		{
            ft_pb(stack_a, stack_b); // Déplacer vers stack_b
			ft_rev_sort2(stack_b); 
			ft_rev_sort3(stack_b);

        }
		else
		{
            ft_ra(stack_a); // Décaler vers le haut
        }
        count++;
    }
}
