/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_sort4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:16:26 by calberti          #+#    #+#             */
/*   Updated: 2024/12/10 12:24:33 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Fonction pour trier 4 éléments
void    ft_rev_sort4(t_stack **stack_a, t_stack **stack_b) 
{
    printf("rev sort 4\n");
    // Déplacer le plus petit élément dans `b`
    int max_pos = find_max_pos(*stack_b);
    move_max_to_top(stack_b, max_pos);
    if (ft_is_revsort(*stack_b) == 0)
        return;
    ft_pa(stack_a, stack_b);

    // Trier les trois éléments restants dans `a`
    ft_rev_sort3(stack_b);

    // Réinsérer l'élément de `b` dans `a`
    ft_pb(stack_a, stack_b);
}
