/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:12:57 by calberti          #+#    #+#             */
/*   Updated: 2025/01/13 22:37:03 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	ft_format(va_list *args, char c)
{
	int					len;
	unsigned long int	ptr;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(*args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(*args, char *));
	else if (c == 'p')
	{
		ptr = va_arg(*args, unsigned long int);
		if (!ptr)
			return (len += write(1, "(nil)", 5));
		len += write(1, "0x", 2);
		len += ft_ptr(ptr);
	}
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(*args, int));
	else if (c == 'u')
		len += ft_putnbrui(va_arg(*args, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_hexa(va_arg(*args, unsigned int), c);
	else if (c == '%')
		len += ft_putchar(c);
	return (len);
}
