/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 23:06:49 by calberti          #+#    #+#             */
/*   Updated: 2024/12/13 23:11:59 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_only_int(char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if (!((str[i] >= 48 && str[i] <= 57)
				|| (str[i] == 32) || (str[i] == 45) || (str[i] == 43)))
			return (1);
		if (str[i] == 45 || str[i] == 43)
		{
			i++;
			if (!(str[i] >= 48 && str[i] <= 57))
				return (1);
		}
		if (str[i] >= 48 && str[i] <= 57)
			nbr = 1;
		i ++;
	}
	if (nbr == 0)
		return (1);
	return (0);
}
