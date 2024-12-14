/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:37:15 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 01:30:54 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min_pos(t_stack *stack)
{
	t_stack	*current;
	int		min;
	int		pos;
	int		min_pos;

	min = INT_MAX;
	pos = 0;
	min_pos = 0;
	current = stack;
	while (current)
	{
		if (*(current->content) < min)
		{
			min = *(current->content);
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

void	move_min_to_top(t_stack **stack, int min_pos)
{
	t_stack	*current;
	int		size;

	size = 0;
	current = *stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	if (min_pos <= size / 2)
	{
		while (min_pos--)
			ft_ra(stack);
	}
	else
	{
		min_pos = size - min_pos;
		while (min_pos--)
			ft_rra(stack);
	}
}

void	ft_sort5(t_stack **stack_a, t_stack **stack_b)
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
	ft_sort3(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}
