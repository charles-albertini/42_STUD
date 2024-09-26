#include "push_swap.h"

t_stack *ft_lstnull(int size)
{
    t_stack *stack = NULL;
    t_stack *current = NULL;
	int i;

	i = 0;
    while (i < size)
	{
        t_stack *new_node = malloc(sizeof(t_stack));
        new_node->content = NULL; // Contenu initialisé à NULL
        new_node->next = NULL;

        // Ajout du nouveau nœud à la pile
        if (stack == NULL) {
            stack = new_node; // Le premier nœud devient le nœud de tête
            current = stack; // Initialiser le pointeur courant
        } else {
            current->next = new_node; // Ajouter le nouveau nœud
            current = current->next; // Passer au nœud courant
        }
		i++;
    }

    return (stack); // Retourner le pointeur vers la pile nouvellement créée
}
