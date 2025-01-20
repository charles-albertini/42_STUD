/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:19:12 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 01:17:19 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move3(int a, int b, int c, t_stack **stack_a)
{
	if (a > b && b < c && a < c)
		ft_sa(stack_a);
	else if (a > b && b > c)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ft_ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		ft_rra(stack_a);
}

void	ft_sort3(t_stack **stack_a)
{
	t_stack	*current;
	int		a;
	int		b;
	int		c;

	current = *stack_a;
	if (current != NULL && current->next != NULL && current->next->next != NULL)
	{
		a = *(current->content);
		b = *(current->next->content);
		c = *(current->next->next->content);
		move3(a, b, c, stack_a);
	}
}
