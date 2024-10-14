/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:36:28 by calberti          #+#    #+#             */
/*   Updated: 2024/10/14 12:36:31 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char *)s;
	if (c == '\0')
	{
		i = ft_strlen((char *)s);
		return ((char *)&str[i]);
	}
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv)
{
	char	*i;
	char	*j;

	if (argc == 3)
	{
		i = ft_strchr(argv[1], atoi (argv[2]));
		j = strchr(argv[1], atoi (argv[2]));
		printf("Mine : %s\nReal : %s\n", i, j);
	}
	return (0);
}
*/
