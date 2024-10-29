/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:36:22 by calberti          #+#    #+#             */
/*   Updated: 2024/10/29 23:31:53 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

char	*ft_creat(char const *str, int first, int last)
{
	char	*out;
	int		i;
	int		size;

	size = last - first;
	out = malloc(sizeof(char) * (size + 1));
	if (out == NULL)
		return(NULL);
	i = 0;
	while (i < size)
	{
		out[i] = str[first + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	**ft_split(char const *str, char charset)
{
	char	**out;
	int		first;
	int		i_out;
	int		i;

	i = 0;
	first = 0;
	i_out = 0;
	out = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	if (out == NULL)
		return (NULL);
	while (str[i])
	{
		while (str[i] && ft_find(str[i], charset) == 1)
			i++;
		first = i;
		while (str[i] && ft_find(str[i], charset) == 0)
			i++;
		if (first != i)
		{
			out[i_out] = ft_creat(str, first, i);
			i_out ++;
		}
	}
	out[i_out] = 0;
	return (out);
}

/*
#include <stdio.h>

int	main(void)
{
	char	**out;
	int		i;

	out = ft_split("  tripouille  42  ", ' ');
	i = 0;
	while (out[i])
	{
		printf("%s\n", out[i]);
		free (out[i]);
		i++;
	}
	free(out);
}
*/
