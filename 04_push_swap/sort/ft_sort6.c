/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:30:35 by calberti          #+#    #+#             */
/*   Updated: 2024/12/15 20:32:12 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort6(t_stack **stack_a, t_stack **stack_b)
{
	int	min_pos;

	min_pos = find_min_pos(*stack_a);
	move_min_to_top(stack_a, min_pos);
	if (ft_issort(*stack_a) == 0)
		return ;
	ft_pb(stack_a, stack_b);
	min_pos = find_min_pos(*stack_a);
	move_min_to_top(stack_a, min_pos);
	if (ft_issort(*stack_a) == 0)
		return ;
	ft_pb(stack_a, stack_b);
	min_pos = find_min_pos(*stack_a);
	move_min_to_top(stack_a, min_pos);
	ft_pb(stack_a, stack_b);
	ft_sort3(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}
