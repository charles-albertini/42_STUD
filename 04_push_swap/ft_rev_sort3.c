#include "push_swap.h"

void ft_rev_sort3(t_stack **stack_b)
{
    t_stack *current = *stack_b;
	//t_stack *third_next = NULL;

	if (current != NULL && current->next != NULL && current->next->next != NULL)
	{
		//third_next = current->next->next->next; // Sauvegarde du quatrième élément
    	//current->next->next->next = NULL;// On coupe temporairement la liste après les trois premiers éléments

		int a = *(current->content);
    	int b = *(current->next->content);
    	int c = *(current->next->next->content);

    	if (a < b && b > c && a > c)
        	ft_sb(stack_b); // Cas 2 1 3
    	else if (a < b && b < c)
    	{
        	ft_sb(stack_b); // Cas 3 2 1
        	ft_rrb(stack_b); // Faire descendre le plus grand au bas
    	}
    	else if (a < b && b > c && a < c)
        	ft_rb(stack_b); // Cas 3 1 2
    	else if (a > b && b < c && a > c)
    	{
        	ft_sb(stack_b); // Cas 1 3 2
        	ft_rb(stack_b); // Faire remonter le plus petit en haut
    	}
    	else if (a > b && b < c && a < c)
        	ft_rrb(stack_b); // Cas 2 3 1
		}

		// Réattacher le reste de la liste
    	//current = *stack_b;
    	//while (current->next != NULL)
        	//current = current->next;
    	//current->next = third_next;


}
