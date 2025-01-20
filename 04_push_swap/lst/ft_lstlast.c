/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:30:04 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 00:59:51 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	int	i;
	int	len;

	i = 0;
	len = ft_lstsize(lst);
	while (i < len - 1)
	{
		lst = lst -> next;
		i ++;
	}
	return (lst);
}
