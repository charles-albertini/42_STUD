/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 02:09:49 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 04:01:57 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_chunk_count(int size)
{
	if (size <= 50)
		return (3);
	else if (size <= 200)
		return (6);
	else if (size <= 500)
		return (16);
	else
		return (10);
}

void	reinsert_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	max_pos;

	while (*stack_b)
	{
		max_pos = find_max_pos(*stack_b);
		if (max_pos == -1)
			break ;
		if (max_pos >= 0)
		{
			move_to_top(stack_b, max_pos);
			ft_pa(stack_a, stack_b);
		}
		else
			break ;
	}
}

int	find_max_pos(t_stack *stack)
{
	t_stack	*current;
	int		max;
	int		pos;
	int		max_pos;

	max = *(stack->content);
	pos = 0;
	max_pos = 0;
	current = stack;
	while (current)
	{
		if (*(current->content) > max)
		{
			max = *(current->content);
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

void	move_to_top(t_stack **stack, int pos)
{
	t_stack	*current;
	int		size;

	if (!stack || pos < 0)
		return ;
	size = 0;
	current = *stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ft_rb(stack);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			ft_rrb(stack);
	}
}

void	push_chunk_to_b(t_stack **stack_a, t_stack **stack_b, int min, int max)
{
	t_stack	*current;
	int		num;
	int		total_elements;

	current = *stack_a;
	total_elements = 0;
	while (current)
	{
		total_elements++;
		current = current->next;
	}
	while (total_elements > 0)
	{
		num = *((*stack_a)->content);
		if (num >= min && num <= max)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
		total_elements--;
	}
}
