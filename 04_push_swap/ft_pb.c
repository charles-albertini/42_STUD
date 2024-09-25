#include "push_swap.h"

void ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *new;
	int *nb;

	nb = (*stack_a) -> content;
	new = ft_lstnew(nb);

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return;
	ft_lstadd_front(stack_b, new);
	ft_lstdelone(stack_a);

	write(1, "pb\n", 3);

}
