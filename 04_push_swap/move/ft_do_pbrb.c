/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_pbrb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 07:06:36 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 07:07:58 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_do_pbrb(t_stack **stack_a, t_stack **stack_b)
{
	ft_pb(stack_a, stack_b);
	ft_rb(stack_b);
}
