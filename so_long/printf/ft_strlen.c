/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:14:37 by calberti          #+#    #+#             */
/*   Updated: 2025/01/10 18:35:27 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>
int main (int argc, char **argv)
{

	if (argc == 2)
	{
	    printf("%ld \n", ft_strlen(argv[1]));
	    printf("%ld \n", strlen(argv[1]));
	}
	return(0);
}
*/
