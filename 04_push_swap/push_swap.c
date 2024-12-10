#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int size_a;
	//int size_b;
	//int pivot;
	//int verif_pivot;

	if (argc == 1) // fonction (stack_a, argc, argv) pour remplir stack_a
		return(0);
	if (argc == 2)
		stack_a = ft_getarg_str(argv[1]);
	else
		stack_a = ft_getarg(argc, argv);
	stack_b = NULL;
	if (stack_a == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}

	size_a = ft_lstsize(stack_a);
	// ft_sort(size_a, &stack_a, &stack_b);
	// pivot = ft_pivot(stack_a, size_a);
	// while((ft_issort(stack_a) == 1))
	// {
	// 	size_a = ft_lstsize(stack_a);
	// 	while (size_a > 6 || ft_issort(stack_a) == 1)
	// 	{
	// 		ft_sort_pivot(&stack_a, &stack_b, pivot);
	// 		size_a = ft_lstsize(stack_a);
	// 		pivot = ft_pivot(stack_a, size_a);
	// 	}
	// 	size_a = ft_lstsize(stack_a);
	// 	ft_sort(size_a, &stack_a, &stack_b);

	// 	size_b = ft_lstsize(stack_b);
	// 	verif_pivot = pivot;
	// 	pivot = ft_pivot(stack_b, size_b);
	// 	if (pivot == verif_pivot)
	// 		pivot = ft_new_pivot(stack_b, size_b);
	// 	while (stack_b)
    //     	ft_pa(&stack_a, &stack_b);
	// }

	if (ft_issort(stack_a) == 1)
		chunk_sort_optimized(&stack_a, &stack_b, size_a);

	// printf("liste a:\n");
	// aff_lst(stack_a);
	// printf("\n");
	// printf("liste b:\n");
	// aff_lst(stack_b);


}

/*
	(void)argc;
	(void)argv;
	int nb = 10;
	int nb2 = 9;
	int nb3 = 11;
	int size;

	t_stack *first = ft_lstnew(&nb);
	t_stack *new = ft_lstnew(&nb2);
	t_stack *new2 = ft_lstnew(&nb3);

	ft_lstadd_front(&first, new);
	ft_lstadd_back(&first, new2);

	printf("liste:\n");
	aff_lst(first);

	size = ft_lstsize(first);
	printf("\nsize: \n%d\n", size);

	printf("\nlast list:\n");
	aff_lst(ft_lstlast(first));

	//ft_lstclear(&first, *ft_del);
	//aff_lst(first);

	//ft_lstiter(first, *ft_addone);
	//printf("\niteration:\n");
	//aff_lst(first);

	t_list *testmap = ft_lstmap(first, double_value, ft_del);
	printf("\nmap:\n");
	aff_lst(testmap);
	*/
