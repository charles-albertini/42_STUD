#include "../push_swap.h"

void ft_sb(t_stack **stack_b)
{
		// Vérifier si la liste a au moins deux éléments
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return;

	// Pointeur vers les deux premiers éléments
	t_stack *first = *stack_b;
	t_stack *second = first->next;

	// Inverser les deux premiers éléments
	first->next = second->next;  // Le premier pointe désormais vers le troisième élément (ou NULL)
	second->next = first;        // Le second pointe vers le premier
	*stack_b = second;               // La tête de la liste est maintenant le second nœud
	write(1, "sb\n", 3);

}
