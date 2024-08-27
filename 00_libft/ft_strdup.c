/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:52:03 by calberti          #+#    #+#             */
/*   Updated: 2024/07/11 20:24:12 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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

char	*ft_strcpy(char *dest, char *src)
{
	int	nbr;

	nbr = 0;
	while (src[nbr])
	{
		dest [nbr] = src [nbr];
		nbr ++;
	}
	dest [nbr] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*cpy;

	cpy = malloc(ft_strlen(src) + 1);
	if (cpy == NULL)
		return (NULL);
	cpy = ft_strcpy(cpy, src);
	return (cpy);
}
/*
int	main (void)
{
	char	*str = "phrase a copier";
	char	*strcpy;

	strcpy = ft_strdup(str);
	printf("%s \n", strcpy);
	free(strcpy);		
}
*/
