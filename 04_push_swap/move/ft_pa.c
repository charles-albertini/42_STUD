/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:00:23 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 01:05:15 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new;
	int		*nb;

	if (*stack_b == NULL)
		return ;
	nb = (*stack_b)-> content;
	new = ft_lstnew(nb);
	ft_lstadd_front(stack_a, new);
	ft_lstdelone(stack_b);
	write(1, "pa\n", 3);
}
