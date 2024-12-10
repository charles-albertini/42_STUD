/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlesalbertini <charlesalbertini@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:37:16 by calberti          #+#    #+#             */
/*   Updated: 2024/10/31 16:07:30 by charlesalbe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char src[] = "salutsalut";
	char dest[] = "comment";
	printf("%zu | %s", ft_strlcpy(dest, src, 8), dest);
	printf("\n");
	printf("%zu | %s", strlcpy(dest, src, 8), dest);
	printf("\n");
}
*/
/*
on copie mais y a une securite avec size qui est
la taile max du buffer de dest
il faut compiler avec -lbsd
*/
