/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:01:18 by calberti          #+#    #+#             */
/*   Updated: 2025/01/14 01:32:14 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_stack **stack_a)
{
	t_stack	*new;
	int		*nb;

	nb = (*stack_a)-> content;
	
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	new = ft_lstnew(nb);
	ft_lstadd_back(stack_a, new);
	ft_lstdelone(stack_a);
	write(1, "ra\n", 3);
}
