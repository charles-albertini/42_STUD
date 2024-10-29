/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:34:31 by calberti          #+#    #+#             */
/*   Updated: 2024/10/29 21:38:58 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	i = 0;
	s2 = (unsigned char *)s; // on cast en unsigned char pcq ca correspond a 1 octet
	while (i < n)
	{
		if (s2[i] == (unsigned char)c)
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
