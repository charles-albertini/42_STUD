#include "push_swap.h"

void ft_sort3(t_stack **stack_a)
{
    t_stack *current = *stack_a;
	//t_stack *third_next = NULL;

	if (current != NULL && current->next != NULL && current->next->next != NULL)
	{
		//third_next = current->next->next->next; // Sauvegarde du quatrième élément
    	//current->next->next->next = NULL;// On coupe temporairement la liste après les trois premiers éléments

		int a = *(current->content);
    	int b = *(current->next->content);
    	int c = *(current->next->next->content);

    	if (a > b && b < c && a < c)
        	ft_sa(stack_a); // Cas 2 1 3
    	else if (a > b && b > c)
    	{
        	ft_sa(stack_a); // Cas 3 2 1
        	ft_rra(stack_a); // Faire descendre le plus grand au bas
    	}
   		else if (a > b && b < c && a > c)
        	ft_ra(stack_a); // Cas 3 1 2
    	else if (a < b && b > c && a < c)
   		{
       		ft_sa(stack_a); // Cas 1 3 2
       		ft_ra(stack_a); // Faire remonter le plus petit en haut
    	}
   		else if (a < b && b > c && a > c)
        	ft_rra(stack_a); // Cas 2 3 1
		}

		 // Réattacher le reste de la liste
    	//current = *stack_a;
    	//while (current->next != NULL)
        	//current = current->next;
    	//current->next = third_next;


}
