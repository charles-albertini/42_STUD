/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:08:49 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 01:13:59 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*first2;
	t_stack	*second2;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first2 = *stack_b;
	second2 = first2->next;
	first2->next = second2->next;
	second2->next = first2;
	*stack_b = second2;
	write(1, "ss\n", 3);
}
