/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 23:12:24 by calberti          #+#    #+#             */
/*   Updated: 2025/01/14 01:20:30 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	checker_arg2(int argc, char **argv)
{
	while (argc > 1)
	{
		if (ft_only_int (argv[argc]))
			return (1);
		if ((ft_atoi(argv[argc]) == 1) && (ft_strlen(argv[argc]) > 9) && argv[argc][0] != '-')
			return (1);
		if ((ft_atoi(argv[argc]) == 1) && (ft_strlen(argv[argc]) > 10))
			return (1);
		argc--;
	}
	
	return (0);
}

t_stack	*ft_getarg(int argc, char **argv)
{
	int		*nb_add;
	t_stack	*first;
	t_stack	*new;

	argc--;
	if (checker_arg2(argc, argv) == 1)
		return (NULL);
	nb_add = malloc(sizeof(int));
	*nb_add = ft_atoi(argv[argc]);
	first = ft_lstnew(nb_add);
	while (argc > 1)
	{
		argc--;
		if (checker_arg2(argc, argv) == 1)
			return (NULL);
		nb_add = malloc(sizeof(int));
		*nb_add = ft_atoi(argv[argc]);
		if (ft_findarg(nb_add, first) == 0)
			return (free(nb_add), free_stack(&first), NULL);
		new = ft_lstnew(nb_add);
		if (!(new))
			return (NULL);
		ft_lstadd_front(&first, new);
	}
	return (first);
}
