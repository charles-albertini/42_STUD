/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:50:43 by calberti          #+#    #+#             */
/*   Updated: 2024/12/16 22:42:10 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	if (ft_only_int(argv[1]) == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
		stack_a = ft_getarg_str(argv[1]);
	else
		stack_a = ft_getarg(argc, argv);
	stack_b = NULL;
	if (stack_a == NULL)
	{
		write(2, "Error\n", 6);
		return (free_stack(&stack_a), 0);
	}
	if (ft_lstsize(stack_a) <= 6)
		ft_sort(ft_lstsize(stack_a), &stack_a, &stack_b);
	if (ft_issort(stack_a) == 1)
		chunk_sort_optimized(&stack_a, &stack_b, ft_lstsize(stack_a));
	free_stack(&stack_a);
}
	// printf("liste a:\n");
	// aff_lst(stack_a);
	// printf("\n");
	// printf("liste b:\n");
	// aff_lst(stack_b);
	// free_stack(&stack_a);
