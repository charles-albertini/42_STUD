/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:37:16 by calberti          #+#    #+#             */
/*   Updated: 2024/10/14 12:37:20 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src [i] != '\0' && i < size - 1)
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
	char src[] = "salut";
	char dest[] = "comment ca va ici";
	printf("%zu | %s", ft_strlcpy(dest, src, 4), dest);
	printf("\n");
	printf("%zu | %s", strlcpy(dest, src, 4), dest);
}
*/
