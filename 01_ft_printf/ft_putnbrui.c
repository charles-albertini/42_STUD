/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:14:27 by calberti          #+#    #+#             */
/*   Updated: 2024/10/30 19:14:28 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrui(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putnbrui(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}
/*
#include <stdio.h>

int main (void)
{
    int len = 0;
    len = ft_putnbrui(276354773);
    printf("\n%d\n", len);
}
*/
