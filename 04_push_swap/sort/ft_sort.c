/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 23:56:42 by calberti          #+#    #+#             */
/*   Updated: 2024/12/15 20:33:32 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort(int size_a, t_stack **stack_a, t_stack **stack_b)
{
	if (size_a == 2 && ft_issort(*stack_a) == 1)
		ft_sort2(stack_a);
	if (size_a == 3 && ft_issort(*stack_a) == 1)
		ft_sort3(stack_a);
	if (size_a == 4 && ft_issort(*stack_a) == 1)
		ft_sort4(stack_a, stack_b);
	if (size_a == 5 && ft_issort(*stack_a) == 1)
		ft_sort5(stack_a, stack_b);
	if (size_a == 6 && ft_issort(*stack_a) == 1)
		ft_sort6(stack_a, stack_b);
}
