#include "../push_swap.h"

void ft_sort3(t_stack **stack_a)
{
    t_stack *current = *stack_a;

	if (current != NULL && current->next != NULL && current->next->next != NULL)
	{
		printf("sort 3\n");
		int a = *(current->content);
    	int b = *(current->next->content);
    	int c = *(current->next->next->content);

    	if (a > b && b < c && a < c)
		{
			ft_sa(stack_a);
			//return;
		}
        	
    	else if (a > b && b > c)
    	{
        	ft_sa(stack_a);
        	ft_rra(stack_a);
			//return;
    	}
   		else if (a > b && b < c && a > c)
		{
			ft_ra(stack_a);
			//return;
		}
        	
    	else if (a < b && b > c && a < c)
   		{
       		ft_sa(stack_a);
       		ft_ra(stack_a);
			//return;
    	}
   		else if (a < b && b > c && a > c)
		{
			ft_rra(stack_a);
			//return;
		}
        	
		}
}
