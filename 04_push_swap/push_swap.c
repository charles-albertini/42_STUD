#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc == 1)
		return(0);
	stack_a = ft_getarg(argc, argv);
	stack_b = ft_getarg(argc, argv);
	if (stack_a == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	aff_lst(stack_a);
	printf("\n");
	aff_lst(stack_b);
	ft_rrr(&stack_a, &stack_b);
	aff_lst(stack_a);
	printf("\n");
	aff_lst(stack_b);


}


// LE CAS OU UN ARG EST INFERIEUR A INT_MIN OU SUPERIEUR A INT_MAX N'EST PAS GERER


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
