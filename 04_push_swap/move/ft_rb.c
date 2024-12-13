#include "../push_swap.h"

void ft_rb(t_stack **stack_b)
{
	t_stack *new;
	int *nb;


	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return;
	nb = (*stack_b) -> content;
	new = ft_lstnew(nb); //malloc
	ft_lstadd_back(stack_b, new);
	ft_lstdelone(stack_b);

	write(1, "rb\n", 3);

}
