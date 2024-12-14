/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:26:19 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 01:12:39 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if ((lst == NULL) || (new == NULL))
	{
		return ;
	}
	new->next = *lst;
	*lst = new;
}
