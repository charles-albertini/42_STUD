/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:24:48 by calberti          #+#    #+#             */
/*   Updated: 2024/10/14 12:24:51 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (size != 0 && nmemb > SIZE_MAX / size)
	{
		return (NULL);
	}
	tab = malloc(size * nmemb);
	if (tab == NULL)
	{
		return (NULL);
	}
	ft_bzero(tab, nmemb * size);
	return (tab);
}
/*
int    main(void)
{
    int    *tab;
    tab = ft_calloc(0, 0);
    free(tab);
}
*/
