/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:26:02 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 00:26:09 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*back;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (lst == NULL)
		return ;
	back = ft_lstlast(*lst);
	back->next = new;
}
