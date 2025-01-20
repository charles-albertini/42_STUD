/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:05:45 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 01:13:52 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack_a;
	second = first->next;
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	write(1, "sa\n", 3);
}
