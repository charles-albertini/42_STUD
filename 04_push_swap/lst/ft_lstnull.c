/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:30:33 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 00:59:30 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_new_node(t_stack *new_node)
{
	new_node->content = NULL;
	new_node->next = NULL;
}

t_stack	*ft_lstnull(int size)
{
	t_stack	*stack;
	t_stack	*current;
	t_stack	*new_node;
	int		i;

	i = 0;
	stack = NULL;
	current = NULL;
	while (i < size)
	{
		new_node = malloc(sizeof(t_stack));
		ft_new_node(new_node);
		if (stack == NULL)
		{
			stack = new_node;
			current = stack;
		}
		else
		{
			current->next = new_node;
			current = current->next;
		}
		i++;
	}
	return (stack);
}
