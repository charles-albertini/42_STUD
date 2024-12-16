/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getarg_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:11:12 by calberti          #+#    #+#             */
/*   Updated: 2024/12/16 22:41:17 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

int	check_error(int *nb_add, char *temp, t_stack *first)
{
	if (!(nb_add) || (ft_strlen(temp) > 10)
		|| ((*nb_add == 1 && ft_strlen(temp) > 9)))
	{
		free_stack(&first);
		return (1);
	}
	if (ft_findarg(nb_add, first) == 0)
	{
		free_stack(&first);
		return (1);
	}
	return (0);
}

t_stack	*ft_getarg_str(char *argv)
{
	t_stack	*first;
	char	temp[12];
	int		*nb_add;
	int		i;
	int		j;

	first = NULL;
	i = 0;
	while (argv[i])
	{
		while (argv[i] == ' ')
			i++;
		j = 0;
		if (argv[i] == '+' || argv[i] == '-')
			temp[j++] = argv[i++];
		while (argv[i] >= '0' && argv[i] <= '9')
			temp[j++] = argv[i++];
		temp[j] = '\0';
		nb_add = malloc(sizeof(int));
		*nb_add = ft_atoi(temp);
		if (check_error (nb_add, temp, first))
			return (free(nb_add), NULL);		
		ft_lstadd_back(&first, ft_lstnew(nb_add));
	}
	return (first);
}
