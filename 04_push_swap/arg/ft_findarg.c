/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 23:02:57 by calberti          #+#    #+#             */
/*   Updated: 2024/12/16 22:45:13 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_findarg(int *nb, t_stack *first)
{
	while (first != NULL)
	{
		if (*nb == *(first -> content))
			return (0);
		first = first -> next;
	}
	return (1);
}
