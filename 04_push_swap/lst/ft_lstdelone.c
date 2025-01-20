/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:29:31 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 01:12:48 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstdelone(t_stack **lst)
{
	t_stack	*temp;

	if (*lst == NULL)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	free(temp);
}
