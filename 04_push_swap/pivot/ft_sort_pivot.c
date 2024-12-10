
#include "../push_swap.h"

void ft_sort_pivot(t_stack **stack_a, t_stack **stack_b, int pivot)
{
	int size_a = ft_lstsize(*stack_a);
    int size_b = ft_lstsize(*stack_b);
    int count = 0;

    
    while (count < size_a) 
    {
        if ((*(*stack_a)->content) <= pivot)
		{
            ft_pb(stack_a, stack_b);
			size_b = ft_lstsize(*stack_b);
			ft_rev_sort(size_b, stack_a, stack_b);
        }
		else
		{
            //if (ft_issort(*stack_a) == 0 || ft_lstsize(*stack_a) < 6)
                //return;
            ft_ra(stack_a);
        }
        count++;
        
    }
}
