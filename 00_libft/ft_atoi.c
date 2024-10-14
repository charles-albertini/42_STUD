/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:17:04 by calberti          #+#    #+#             */
/*   Updated: 2024/10/14 12:17:25 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	nbr;
	int	neg;
	int	out;

	nbr = 0;
	neg = 1;
	out = 0;
	while (str[nbr] == ' ' || str[nbr] == '\f' || str[nbr] == '\n'
		|| str[nbr] == '\r' || str[nbr] == '\t' || str[nbr] == '\v')
	{
		nbr ++;
	}
	if (str[nbr] == '+' || str[nbr] == '-')
	{
		if (str[nbr] == '-')
			neg = neg * (-1);
		nbr ++;
	}
	while (str[nbr] >= '0' && str[nbr] <= '9')
	{
		out = out * 10;
		out = out + str[nbr] - '0';
		nbr ++;
	}
	return (neg * out);
}
/*
#include <stdio.h>
 
int main (void)
{	
	printf("%d \n", ft_atoi("    ---123"));
	printf("%d \n", atoi("    ---123"));
}
*/
