/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:03:13 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 01:05:24 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_stack **stack_a)
{
	t_stack	*new;
	int		*nb;

	nb = ft_lstlast(*stack_a)-> content;
	new = ft_lstnew(nb);
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	ft_lstadd_front(stack_a, new);
	ft_lstdellast(stack_a);
	write(1, "rra\n", 4);
}
