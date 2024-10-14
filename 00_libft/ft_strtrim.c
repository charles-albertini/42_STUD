/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:38:11 by calberti          #+#    #+#             */
/*   Updated: 2024/10/14 12:38:13 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nb_char(char const *str, char const *find)
{
	int	nb;
	int	i;
	int	j;

	nb = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		while (find[j])
		{
			if (str[i] == find[j])
				nb ++;
			j ++;
		}
		j = 0;
		i ++;
	}
	return (nb);
}

int	ft_char_is(char const c, char const *find)
{
	int	i;

	i = 0;
	while (find[i])
	{
		if (find[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	int		i;
	int		j;

	i = 0;
	j = 0;
	out = malloc (sizeof(char) * (ft_strlen(s1) - (ft_nb_char(s1, set)) + 1));
	while (s1[i])
	{
		if (ft_char_is(s1[i], set) == 1)
			i ++;
		else
		{
			out[j] = s1[i];
			j ++;
			i ++;
		}
	}
	return (out);
}
/*
 #include <string.h>
 #include <stdio.h>
 
 int    main(int argc, char **argv)
 {
 if (argc == 3)
 {
 printf("%s\n", ft_strtrim(argv[1], argv[2]));
 }
 
 
 }
 */
