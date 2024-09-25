#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int	nb;

	nb = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		nb ++;
	}
	return (nb);
}
/*
#include <stdio.h>

void aff_lst(t_stack *lst)
{
	while (lst != NULL)
	{
		printf("%d\n", *(int *)(lst -> content));
		lst = lst -> next;
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int nb = 10;
	int nb2 = 9;
	int nb3 = 8;
	int size;
	t_stack *first = ft_lstnew(&nb);
	t_stack *new = ft_lstnew(&nb2);
	t_stack *new2 = ft_lstnew(&nb3);
	ft_lstadd_front(&first, new);
	ft_lstadd_front(&first, new2);
	size = ft_lstsize(first);
	aff_lst(first);
	printf("\n%d\n", size);



	return (0);
}
*/
