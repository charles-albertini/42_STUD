/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 04:43:22 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 06:29:46 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_total_element(t_stack **stack_a)
{
	t_stack	*current;
	int		total_elements;

	total_elements = 0;
	current = *stack_a;
	while (current)
	{
		total_elements++;
		current = current->next;
	}
	return (total_elements);
}

int	check_pos_min(t_stack **stack_a, int *array, int size, int min)
{
	if (*((*stack_a)->content) >= array[min]
		&& *((*stack_a)->content) < array[size / 2])
		return (1);
	return (0);
}

int	check_pos_max(t_stack **stack_a, int *array, int size, int max)
{
	if (*((*stack_a)->content) >= array[size / 2]
		&& *((*stack_a)->content) <= array[max])
		return (1);
	return (0);
}
