#include "push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*back;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (lst == NULL)
		return ;
	back = ft_lstlast(*lst);
	back->next = new;
}
/*
#include stdio.h>

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
	int nb3 = 11;
	int size;

	t_stack *first = ft_lstnew(&nb);
	t_stack *new = ft_lstnew(&nb2);
	t_stack *new2 = ft_lstnew(&nb3);

	ft_lstadd_front(&first, new);
	ft_lstadd_back(&first, new2);
	size = ft_lstsize(first);
	printf("liste :\n");
	aff_lst(first);
	printf("size : %d\n", size);
	printf("last list :");
	aff_lst(ft_lstlast(first));
	

	
	return (0);
}
*/
