#include "../push_swap.h"

void ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;

	t_stack *first = *stack_a;
	t_stack *second = first->next;

	first->next = second->next;
	second->next = first;
	*stack_a = second;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return;

	t_stack *first2 = *stack_b;
	t_stack *second2 = first2->next;

	first2->next = second2->next;
	second2->next = first2;
	*stack_b = second2;
	write(1, "ss\n", 3);

}

