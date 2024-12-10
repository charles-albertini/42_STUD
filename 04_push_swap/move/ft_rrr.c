#include "../push_swap.h"

void ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *new;
	int *nb;
	t_stack *new2;
	int *nb2;

	nb = ft_lstlast(*stack_a) -> content;
	new = ft_lstnew(nb);
	nb2 = ft_lstlast(*stack_b) -> content;
	new2 = ft_lstnew(nb2);

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;
	ft_lstadd_front(stack_a, new);
	ft_lstdellast(stack_a);
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return;
	ft_lstadd_front(stack_b, new2);
	ft_lstdellast(stack_b);


	write(1, "rrr\n", 4);

}
