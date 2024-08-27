/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:50:48 by calberti          #+#    #+#             */
/*   Updated: 2024/07/07 17:12:01 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	nbr;

	nbr = 0;
	while ((s1[nbr] || s2[nbr]) && nbr < n)
	{
		if (s1[nbr] < s2[nbr])
			return (-1);
		if (s1[nbr] > s2[nbr])
			return (1);
		nbr ++;
	}
	return (0);
}
