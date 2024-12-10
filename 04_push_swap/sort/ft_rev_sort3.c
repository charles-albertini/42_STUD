#include "../push_swap.h"

void ft_rev_sort3(t_stack **stack_b)
{
    t_stack *current = *stack_b;

	if (current != NULL && current->next != NULL && current->next->next != NULL)
	{
		printf("rev sort 3\n");
		int a = *(current->content);
    	int b = *(current->next->content);
    	int c = *(current->next->next->content);

    	if (a < b && b > c && a > c)
		{
			ft_sb(stack_b);
			//return;
		}
        	
    	else if (a < b && b < c)
    	{
        	ft_sb(stack_b);
        	ft_rrb(stack_b);
			//return;
    	}
    	else if (a < b && b > c && a < c)
		{
			ft_rb(stack_b);
			//return;
		}
        	
    	else if (a > b && b < c && a > c)
    	{
        	ft_sb(stack_b);
        	ft_rb(stack_b);
			//return;
    	}
    	else if (a > b && b < c && a < c)
		{
			ft_rrb(stack_b);
			//return;
		}
        	
		}
}
