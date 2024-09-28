#include "push_swap.h"

int ft_pivot(t_stack *stack, int size)
{
	// on met tout les content dans un tableau d'entier
    int *values = malloc(size * sizeof(int));
    int i = 0;
    while (stack) {
        values[i++] = *(stack->content);
        stack = stack->next;
    }
    // Tri des valeurs pour trouver le pivot (Bubble sort)
    int j = 0;
    while (j < size - 1) {
        int k = 0;
        while (k < size - j - 1) {
            if (values[k] > values[k + 1]) {
                int temp = values[k];
                values[k] = values[k + 1];
                values[k + 1] = temp;
            }
            k++;
        }
        j++;
    }
    int pivot = values[size / 2]; // On prend le pivot médian
    free(values);
    return pivot;
}
