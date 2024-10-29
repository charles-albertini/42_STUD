/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:37:10 by calberti          #+#    #+#             */
/*   Updated: 2024/10/29 20:46:55 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dest) // si on a pas la place de copier 
		return (size + len_src);
	while (src[i] != '\0' && i < (size - len_dest - 1))
	{
		dst[len_dest + i] = src[i];
		i++;
	}
	dst[len_dest + i] = '\0';
	return (len_dest + len_src);
}



/*
#include <string.h>
#include <stdio.h>
 
int main (void)
{
char  dest[10] = "salut";
const char *src = "comment";
unsigned int i = 0;
 
printf("%zu \n", ft_strlcat(dest, src, i));
printf("%s \n", dest);
//n = size de dest - len de dest - 1 = 12 - 5 - 1 = 6
 
}
*/

