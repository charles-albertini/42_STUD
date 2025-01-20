/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:07:10 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 01:13:56 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack_b;
	second = first->next;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	write(1, "sb\n", 3);
}
