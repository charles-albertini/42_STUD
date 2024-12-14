/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:22:32 by calberti          #+#    #+#             */
/*   Updated: 2024/12/14 01:11:35 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int				nbr;
	long long		neg;
	long long		out;

	nbr = 0;
	neg = 1;
	out = 0;
	while (str[nbr] == 32)
		nbr ++;
	if (str[nbr] == '+' || str[nbr] == '-')
	{
		if (str[nbr] == '-')
			neg = neg * (-1);
		nbr ++;
	}
	while (str[nbr] >= '0' && str[nbr] <= '9')
	{
		out = out * 10 + (str[nbr] - '0');
		nbr ++;
		if ((out * neg > INT_MAX) || (neg == -1 && out
				* neg < INT_MIN))
			return (1);
	}
	return ((int)neg * (int)out);
}
