/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:34:55 by calberti          #+#    #+#             */
/*   Updated: 2025/03/14 19:28:20 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s3;
	const unsigned char	*s4;

	i = 0;
	s3 = s1;
	s4 = s2;
	if (n == 0)
	{
		return (0);
	}
	while (s3[i] == s4[i] && i < n - 1)
	{
		i++;
	}
	return (s3[i] - s4[i]);
}
/*
#include <stdio.h>
#include <string.h>
int    main(int argc, char **argv)
{
    int    i;
    int    j;

    if (argc == 4)
    {
        i = ft_memcmp(argv[1], argv[2], atoi(argv[3]));
        j = memcmp(argv[1], argv[2], atoi(argv[3]));
        printf("Mine : %d\nReal : %d\n", i, j);
    }
    return (0);
}
*/
