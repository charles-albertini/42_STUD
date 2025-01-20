/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 23:58:04 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 07:11:29 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adjust_limits(int *min, int *max, int size)
{
	*min -= size / calculate_chunk_count(size);
	*max += size / calculate_chunk_count(size);
	if (*min < 0)
		*min = 0;
	if (*max > size - 1)
		*max = size - 1;
}

void	process_mid(t_stack **stack_a, t_stack **stack_b, int *array, int size)
{
	int		min;
	int		max;
	int		total_elements;
	int		processed_elements;

	min = size / 2 - size / calculate_chunk_count(size) / 2;
	max = size / 2 + size / calculate_chunk_count(size) / 2;
	while ((min >= 0 || max < size) && get_total_element(stack_a) != 0)
	{
		total_elements = get_total_element(stack_a);
		processed_elements = 0;
		while (processed_elements < total_elements)
		{
			if (!*stack_a)
				break ;
			if (check_pos_min(stack_a, array, size, min) == 1)
				ft_do_pbrb(stack_a, stack_b);
			else if (check_pos_max(stack_a, array, size, max) == 1)
				ft_pb(stack_a, stack_b);
			else
				ft_ra(stack_a);
			processed_elements++;
		}
		adjust_limits(&min, &max, size);
	}
}

void	fill_tab(t_stack *current, int *sorted_array)
{
	int	i;

	i = 0;
	while (current)
	{
		sorted_array[i++] = *(current->content);
		current = current->next;
	}
}

void	generate_sorted_array(t_stack *stack_a, int *sorted_array, int size)
{
	t_stack	*current;
	int		i;
	int		swapped;
	int		temp;

	current = stack_a;
	fill_tab(current, sorted_array);
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (sorted_array[i] > sorted_array[i + 1])
			{
				temp = sorted_array[i];
				sorted_array[i] = sorted_array[i + 1];
				sorted_array[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

void	chunk_sort_optimized(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	*array;

	array = malloc(size * sizeof(int));
	if (!array)
		return ;
	generate_sorted_array(*stack_a, array, size);
	process_mid(stack_a, stack_b, array, size);
	reinsert_to_a(stack_a, stack_b);
	free(array);
}
