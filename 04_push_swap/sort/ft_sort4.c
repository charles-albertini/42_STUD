/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:36:55 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 01:24:13 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort4(t_stack **stack_a, t_stack **stack_b)
{
	int	min_pos;

	min_pos = find_min_pos(*stack_a);
	move_min_to_top(stack_a, min_pos);
	ft_pb(stack_a, stack_b);
	ft_sort3(stack_a);
	ft_pa(stack_a, stack_b);
}
