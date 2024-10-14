/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:37:10 by calberti          #+#    #+#             */
/*   Updated: 2024/10/14 12:37:12 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	nbr;
	size_t	size_dest;

	nbr = 0;
	size_dest = ft_strlen(src);
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
#include <string.h>
#include <stdio.h>
 
int main (void)
{
char  *test = "salut";
char *test2 = "bommmmlkh";
unsigned int i = 3;
 
printf("%zu \n", ft_strlcat(test, test2, i));
printf("%zu \n", strlcat(test, test2, i));
//printf("%s \n", test);
//n = size de dest - len de dest - 1 = 12 - 5 - 1 = 6
 
}
*/
