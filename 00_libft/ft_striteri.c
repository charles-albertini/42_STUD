/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlesalbertini <charlesalbertini@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:36:57 by calberti          #+#    #+#             */
/*   Updated: 2024/10/31 16:07:09 by charlesalbe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void    f(unsigned int i, char *s)
{
    write(1, &s[i], 1);
}
int    main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_striteri(argv[1], f);
    }
    return (0);
}
*/
