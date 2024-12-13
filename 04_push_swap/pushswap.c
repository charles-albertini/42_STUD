#include "push_swap.h"

int find_max_pos(t_stack *stack) 
{ 
    int max = *(stack->content);
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


void move_to_top(t_stack **stack, int pos, char stack_name) {
    if (!stack || pos < 0) // Vérifier si la pile est vide ou la position est invalide
        return;

    int size = 0;
    t_stack *current = *stack;

    // Calculer la taille de la pile
    while (current) {
        size++;
        current = current->next;
    }

    if (pos <= size / 2) {
        while (pos-- > 0) {
            if (stack_name == 'a') 
                ft_ra(stack);
            else 
                ft_rb(stack);
        }
    } else {
        pos = size - pos;
        while (pos-- > 0) {
            if (stack_name == 'a') ft_rra(stack);
            else ft_rrb(stack);
        }
    }
}


void push_chunk_to_b(t_stack **stack_a, t_stack **stack_b, int min, int max) {
    int total_elements = 0;
    t_stack *current = *stack_a;

    // Calculer la taille de la pile `a`
    while (current) {
        total_elements++;
        current = current->next;
    }
    

    while (total_elements > 0) {
        int num = *((*stack_a)->content);

        if (num >= min && num <= max) 
        {
            ft_pb(stack_a, stack_b); // Pousser dans `b`
        } 
        else 
        {
            ft_ra(stack_a); // Sinon, rotation dans `a`
        }

        total_elements--;
    }
}



void process_middle_to_extremes(t_stack **stack_a, t_stack **stack_b, int *sorted_array, int size, int chunk_size) {
    int min = size / 2 -  chunk_size/ 2; // Initialiser la plage centrale
    int max = size / 2 +  chunk_size/ 2; 

    while (min >= 0 || max < size) { // Tant qu'il reste des valeurs à traiter
        int total_elements = 0;
        t_stack *current = *stack_a;

        // Calculer le nombre d'éléments dans `stack_a`
        while (current) {
            total_elements++;
            current = current->next;
        }
        if (total_elements == 0)
            break;

        // Traiter tous les éléments de `stack_a`
        int processed_elements = 0; // Compteur pour éviter une boucle infinie
        while (processed_elements < total_elements) {
            if (!*stack_a) break; // Vérifie que `stack_a` n'est pas vide

            int num = *((*stack_a)->content);

            // Si l'élément est dans [min, milieu]
            if (num >= sorted_array[min] && num < sorted_array[size / 2]) {
                ft_pb(stack_a, stack_b); // Pousser dans `b`
                ft_rb(stack_b);          // Envoyer en bas de `b`
            }
            // Si l'élément est dans [milieu, max]
            else if (num >= sorted_array[size / 2] && num <= sorted_array[max]) {
                ft_pb(stack_a, stack_b); // Pousser dans `b`
                
            } 
            // Sinon, effectuer une rotation dans `a`
            else {
                ft_ra(stack_a);
            }

            processed_elements++;
        }

        // Élargir les limites vers les extrémités
        min -= chunk_size /2;
        if (min < 0) min = 0;

        max += chunk_size /2;
        if (max > size - 1) max = size - 1;
    }
}






void reinsert_to_a(t_stack **stack_a, t_stack **stack_b) {
    while (*stack_b) {
        int max_pos = find_max_pos(*stack_b);
        if (max_pos == -1) // Vérifier si `b` est vide
            break;

        // Vérifier que la position est valide
        if (max_pos >= 0) {
            move_to_top(stack_b, max_pos, 'b'); // Amène le maximum en haut
            ft_pa(stack_a, stack_b);           // Réinsérer dans `a`
        } else {
            printf("Erreur : max_pos invalide\n");
            break;
        }
    }
}



void generate_sorted_array(t_stack *stack_a, int *sorted_array, int size) {
    t_stack *current = stack_a;
    int i = 0;

    // Copier les valeurs dans un tableau
    while (current) {
        sorted_array[i++] = *(current->content);
        current = current->next;
    }

    // Trier le tableau (tri à bulles sans `for`)
    int swapped = 1;
    while (swapped) {
        swapped = 0;
        i = 0;
        while (i < size - 1) {
            if (sorted_array[i] > sorted_array[i + 1]) {
                int temp = sorted_array[i];
                sorted_array[i] = sorted_array[i + 1];
                sorted_array[i + 1] = temp;
                swapped = 1;
            }
            i++;
        }
    }
}

int calculate_chunk_count(int size) {
    if (size <= 50) {
        return 3; // Petit nombre de chunks pour une petite pile
    } else if (size <= 200) {
        return 6; // 4 chunks pour une pile de taille moyenne
    } else if (size <= 500) {
        return 10; // 8 chunks pour une pile plus grande
    } else {
        return 10; // 10 chunks pour une très grande pile
    }
}


void chunk_sort_optimized(t_stack **stack_a, t_stack **stack_b, int size) {
    int chunk_count = calculate_chunk_count(size);
    int *sorted_array = malloc(size * sizeof(int));
    if (!sorted_array)
        return;
    
    // Générer un tableau trié basé sur les valeurs de `a`
    generate_sorted_array(*stack_a, sorted_array, size);

    // Traiter les chunks
    process_middle_to_extremes(stack_a, stack_b, sorted_array, size, size / chunk_count);

    // Réintégrer les éléments triés depuis `b`
    reinsert_to_a(stack_a, stack_b);

    free(sorted_array);
}
