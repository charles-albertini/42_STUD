
#include "../push_swap.h"


// Fonction pour trouver la position du plus grand élément dans la pile
int find_max_pos5(t_stack *stack) {
    int max = INT_MIN;
    int pos = 0;
    int max_pos = 0;
    t_stack *current = stack;

    while (current) {
        if (*(current->content) > max) {
            max = *(current->content);
            max_pos = pos;
        }
        current = current->next;
        pos++;
    }
    return max_pos;
}

// Fonction pour déplacer l'élément minimum en haut de la pile
void move_max_to_top(t_stack **stack, int max_pos) {
    int size = 0;
    t_stack *current = *stack;

    // Calculer la taille de la pile
    while (current) {
        size++;
        current = current->next;
    }

    // Si le maximum est dans la première moitié, utiliser `rb`
    if (max_pos <= size / 2) {
        while (max_pos--) {
            ft_rb(stack);
        }
    }
    // Sinon, utiliser `rrb`
    else {
        max_pos = size - max_pos;
        while (max_pos--) {
            ft_rrb(stack);
        }
    }
}

// Fonction pour trier 5 éléments
void ft_rev_sort5(t_stack **stack_a, t_stack **stack_b) 
{
    printf("rev sort 5\n");
    // Déplacer le premier plus petit élément dans `b`
    int max_pos = find_max_pos5(*stack_b);
    move_min_to_top(stack_b, max_pos);
    ft_pa(stack_a, stack_b);

    // Déplacer le second plus petit élément dans `b`
    max_pos = find_max_pos5(*stack_b);
    move_max_to_top(stack_b, max_pos);
    ft_pa(stack_a, stack_b);

    // Trier les trois éléments restants dans `a`
    ft_rev_sort3(stack_b);
    
    // Réinsérer les deux éléments de `b` dans `a`
    ft_pb(stack_a, stack_b);
    ft_pb(stack_a, stack_b);
}