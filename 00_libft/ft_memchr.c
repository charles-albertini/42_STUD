/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:34:31 by calberti          #+#    #+#             */
/*   Updated: 2024/10/14 12:34:34 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	i = 0;
	s2 = (unsigned char *)s;
	while (i < n)
	{
		if ((int)s2[i] == c)
		{
			return (&s2[i]);
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int    main(int argc, char **argv)
{
    char    *i;
    char    *j;

    if (argc == 4)
    {
        i = ft_memchr(argv[1], atoi(argv[2]), atoi(argv[3]));
        j = memchr(argv[1], atoi(argv[2]), atoi(argv[3]));
        printf("Mine : %s\nReal : %s\n", i, j);
    }
    return (0);
}
*/
