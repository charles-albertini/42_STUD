/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:17:16 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 01:23:03 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort2(t_stack **stack_a)
{
	t_stack	*current;
	int		a;
	int		b;

	current = *stack_a;
	if (current != NULL && current->next != NULL)
	{
		a = *(current->content);
		b = *(current->next->content);
		if (a > b)
			ft_sa(stack_a);
	}
}
