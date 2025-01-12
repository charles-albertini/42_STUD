/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:14:32 by calberti          #+#    #+#             */
/*   Updated: 2025/01/10 18:35:25 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i ++;
	}
	return (i);
}
/*
#include <stdio.h>
#include <unistd.h>

int main (int argc, char **argv)
{
	int len =0;

	if (argc == 2)
	{
		len = ft_putstr(argv[1]);
		printf("\n%d\n", len);
	}
}
*/
