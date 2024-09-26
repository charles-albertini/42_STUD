#include "push_swap.h"

void ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *new;
	int *nb;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;

	nb = (*stack_a) -> content;
	new = ft_lstnew(nb);

	ft_lstadd_front(stack_b, new);
	ft_lstdelone(stack_a);

	write(1, "pb\n", 3);

}
