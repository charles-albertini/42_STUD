#include "push_swap.h"

void ft_rrb(t_stack **stack_b)
{
	t_stack *new;
	int *nb;

	nb = ft_lstlast(*stack_b) -> content;
	new = ft_lstnew(nb);

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return;
	ft_lstadd_front(stack_b, new);
	ft_lstdellast(stack_b);


	write(1, "rrb\n", 4);

}
