/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:37:49 by calberti          #+#    #+#             */
/*   Updated: 2024/10/14 12:37:51 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	nbr;

	nbr = 0;
	while ((s1[nbr] || s2[nbr]) && nbr < n)
	{
		if (s1[nbr] < s2[nbr])
			return (s1[nbr] - s2[nbr]);
		if (s1[nbr] > s2[nbr])
			return (s1[nbr] - s2[nbr]);
		nbr ++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main (int argc, char **argv)
{
	size_t n = 5;
	if (argc == 3)
	{
	printf("%d\n", ft_strncmp(argv[1], argv[2], n));
	printf("%d\n", strncmp(argv[1], argv[2], n));

	}
}
*/
