/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:37:15 by calberti          #+#    #+#             */
/*   Updated: 2024/12/09 13:57:56 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


// Fonction pour trouver la position du plus petit élément dans la pile
int find_min_pos(t_stack *stack) {
    int min = INT_MAX;
    int pos = 0;
    int min_pos = 0;
    t_stack *current = stack;

    while (current) {
        if (*(current->content) < min) {
            min = *(current->content);
            min_pos = pos;
        }
        current = current->next;
        pos++;
    }
    return min_pos;
}

// Fonction pour déplacer l'élément minimum en haut de la pile
void move_min_to_top(t_stack **stack, int min_pos) {
    int size = 0;
    t_stack *current = *stack;

    // Calculer la taille de la pile
    while (current) {
        size++;
        current = current->next;
    }

    // Si le minimum est dans la première moitié, utiliser `ra`
    if (min_pos <= size / 2) {
        while (min_pos--) {
            ft_ra(stack);
        }
    }
    // Sinon, utiliser `rra`
    else {
        min_pos = size - min_pos;
        while (min_pos--) {
            ft_rra(stack);
        }
    }
}

// Fonction pour trier 5 éléments
void ft_sort5(t_stack **stack_a, t_stack **stack_b) 
{
    printf("sort 5\n");
    // Déplacer le premier plus petit élément dans `b`
    int min_pos = find_min_pos(*stack_a);
    move_min_to_top(stack_a, min_pos);
    ft_pb(stack_a, stack_b);

    // Déplacer le second plus petit élément dans `b`
    min_pos = find_min_pos(*stack_a);
    move_min_to_top(stack_a, min_pos);
    ft_pb(stack_a, stack_b);

    // Trier les trois éléments restants dans `a`
    ft_sort3(stack_a);
    
    // Réinsérer les deux éléments de `b` dans `a`
    ft_pa(stack_a, stack_b);
    ft_pa(stack_a, stack_b);
}

