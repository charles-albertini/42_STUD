/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:36:55 by calberti          #+#    #+#             */
/*   Updated: 2024/12/10 17:52:47 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Fonction pour trier 4 éléments
void    ft_sort4(t_stack **stack_a, t_stack **stack_b) 
{
    //printf("sort 4\n");
    // Déplacer le plus petit élément dans `b`
    int min_pos = find_min_pos(*stack_a);
    move_min_to_top(stack_a, min_pos);
    ft_pb(stack_a, stack_b);

    // Trier les trois éléments restants dans `a`
    ft_sort3(stack_a);

    // Réinsérer l'élément de `b` dans `a`
    ft_pa(stack_a, stack_b);
}


