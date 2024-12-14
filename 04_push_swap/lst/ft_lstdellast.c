/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdellast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:26:37 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 00:28:58 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstdellast(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*prev;

	if (*lst == NULL)
		return ;
	if ((*lst)->next == NULL)
	{
		free(*lst);
		*lst = NULL;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	free(temp);
}
