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
            if (stack_name == 'a') ft_ra(stack);
            else ft_rb(stack);
        }
    } else {
        pos = size - pos;
        while (pos-- > 0) {
            if (stack_name == 'a') ft_rra(stack);
            else ft_rrb(stack);
        }
    }
}


void push_chunk_to_b(t_stack **stack_a, t_stack **stack_b, int min, int max, int total_elements) {
    if (total_elements <= 0)
        return;

    int num = *((*stack_a)->content);

    if (num >= min && num <= max) {
        ft_pb(stack_a, stack_b); // Pousser dans `b`

        // Organiser partiellement `b` (facultatif pour réduire les coûts de réintégration)
        // if (*stack_b && (*stack_b)->next && *(stack_b[0]->content) < *(stack_b[0]->next->content)) {
        //     ft_sb(stack_b);
        // }
    } else {
        ft_ra(stack_a); // Sinon, rotation dans `a`
    }

    // Traiter le prochain élément
    push_chunk_to_b(stack_a, stack_b, min, max, total_elements - 1);
}

void process_all_chunks(t_stack **stack_a, t_stack **stack_b, int *sorted_array, int size, int chunk_count, int current_chunk) {
    if (current_chunk >= chunk_count)
        return;

    int chunk_size = size / chunk_count;
    int min = current_chunk * chunk_size;
    int max = (current_chunk + 1) * chunk_size - 1;

    if (current_chunk == chunk_count - 1) // Ajuster le dernier chunk
        max = size - 1;

    // Pousser le chunk actuel dans `b`
    push_chunk_to_b(stack_a, stack_b, sorted_array[min], sorted_array[max], size);
    // Passer au chunk suivant
    process_all_chunks(stack_a, stack_b, sorted_array, size, chunk_count, current_chunk + 1);
}


void reinsert_to_a(t_stack **stack_a, t_stack **stack_b) {
    while (*stack_b) {
        int max_pos = find_max_pos(*stack_b);
        if (max_pos == -1) // Si `b` est vide, il n'y a rien à réintégrer
            break;

        move_to_top(stack_b, max_pos, 'b'); // Amène le maximum en haut
        ft_pa(stack_a, stack_b);           // Réinsérer dans `a`

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
    int swapped;
    do {
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
    } while (swapped);
}

void chunk_sort_optimized(t_stack **stack_a, t_stack **stack_b, int size) {
    int chunk_count = 4; // Diviser en 10 chunks (testez avec 5 ou 8 pour des tailles différentes)
    int *sorted_array = malloc(size * sizeof(int));
    if (!sorted_array)
        return;

    // Générer un tableau trié basé sur les valeurs de `a`
    generate_sorted_array(*stack_a, sorted_array, size);

    // Traiter les chunks
    process_all_chunks(stack_a, stack_b, sorted_array, size -1, chunk_count, 0);

    // Réintégrer les éléments triés depuis `b`
    reinsert_to_a(stack_a, stack_b);

    free(sorted_array);
}
