#include "../push_swap.h"

void ft_ra(t_stack **stack_a)
{
	t_stack *new;
	int *nb;

	nb = (*stack_a) -> content;
	new = ft_lstnew(nb);

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;
	ft_lstadd_back(stack_a, new);
	ft_lstdelone(stack_a);


	write(1, "ra\n", 3);

}
