/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 02:33:00 by calberti          #+#    #+#             */
/*   Updated: 2024/07/08 21:22:16 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	nbr;

	nbr = 0;
	while (*str)
	{
		nbr ++;
		str ++;
	}
	return (nbr);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	nbr;
	unsigned int	size_dest;

	nbr = 0;
	size_dest = ft_strlen(dest);
	if (size && dest != src)
	{
		if (size_dest >= size)
		{
			return (size_dest + size);
		}
		while (src[nbr] && nbr < (size - 1))
		{
			dest [size_dest + nbr] = src [nbr];
			nbr ++;
		}
		dest [size_dest + nbr] = 0;
	}
	while (src[nbr])
	{
		nbr ++;
	}
	return (nbr + size_dest);
}
/*
 int main (void)
 {
 char  test [12] = "salut";
 char *test2;
 test2 = "bommmmlkh";
 unsigned int i = 3;
 
 printf("%u \n", ft_strlcat(test, test2, i));
 printf("%s \n", test);
 //n = size de dest - len de dest - 1 = 12 - 5 - 1 = 6
 
 }
 */
