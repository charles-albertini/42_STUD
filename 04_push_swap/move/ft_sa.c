#include "../push_swap.h"

void ft_sa(t_stack **stack_a)
{
		// Vérifier si la liste a au moins deux éléments
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;

	// Pointeur vers les deux premiers éléments
	t_stack *first = *stack_a;
	t_stack *second = first->next;

	// Inverser les deux premiers éléments
	first->next = second->next;  // Le premier pointe désormais vers le troisième élément (ou NULL)
	second->next = first;        // Le second pointe vers le premier
	*stack_a = second;               // La tête de la liste est maintenant le second nœud
	write(1, "sa\n", 3);

}
