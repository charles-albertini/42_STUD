/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:38:18 by calberti          #+#    #+#             */
/*   Updated: 2024/10/14 12:38:20 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	unsigned int	size;
	unsigned int	end;
	char			*out;
	size_t			i;

	i = 0;
	size = ft_strlen ((char *)str);
	end = (unsigned int) len;
	if (start > size)
		return ("");
	if (start + end > size)
		end = size - 1;
	out = malloc(sizeof(char) * ((end - start) + 1));
	if (out == NULL)
		return (NULL);
	while (len > 0)
	{
		out[i] = str[start];
		i ++;
		start ++;
		len --;
	}
	out[start] = '\0';
	return (out);
}
/*
#include <stdio.h>
#include <string.h>

int    main(int argc, char **argv)
{
	char *str;
	if (argc == 4)
	{
	    str = ft_substr(argv[1], atoi(argv[2]), atoi(argv[3]));
	    printf("%s\n", str);
	    free(str);
	}
}
*/
