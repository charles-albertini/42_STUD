/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:00:58 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 01:05:17 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new;
	int		*nb;

	if (*stack_a == NULL)
		return ;
	nb = (*stack_a)-> content;
	new = ft_lstnew(nb);
	ft_lstadd_front(stack_b, new);
	ft_lstdelone(stack_a);
	write(1, "pb\n", 3);
}
